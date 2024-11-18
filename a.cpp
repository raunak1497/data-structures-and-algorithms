#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define mod 1e9 + 7 
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003 
typedef long long int ll; 
typedef vector<int> vi; 
typedef pair<int, int> pi;
#define f first
#define s second
#define pb push_back
#define pob pop_back
#define mp make_pair

vector<vector<pair<int, int>>> graph;

// Fuel station prices (city -> price per liter of fuel)
vector<int> fuelPrices;

struct State {
    int totalCost;    // Total cost so far
    int currentCity;  // Current city
    int fuelLeft;     // Fuel left in the tank

    bool operator>(const State &other) const {
        return totalCost > other.totalCost;
    }
};

int dijkstra(int N, int M, int C, int A, int B) {
    // Priority queue to store {total cost, current city, fuel left}
    priority_queue<State, vector<State>, greater<State>> pq;
    
    // Distance table: city -> fuel left -> minimum cost
    vector<vector<int>> dist(N + 1, vector<int>(C + 1, INF));
    
    // Start from city A with 0 cost and 0 fuel
    pq.push({0, A, 0});
    dist[A][0] = 0;
    
    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();
        
        int totalCost = current.totalCost;
        int currentCity = current.currentCity;
        int fuelLeft = current.fuelLeft;
        
        // If we reached city B, return the total cost
        if (currentCity == B) {
            return totalCost;
        }

        // If we have already found a cheaper way to this state, skip
        if (totalCost > dist[currentCity][fuelLeft]) {
            continue;
        }

        // Explore all adjacent cities
        for (auto &neighbor : graph[currentCity]) {
            int nextCity = neighbor.first;
            int fuelNeeded = neighbor.second;

            if (fuelLeft >= fuelNeeded) {
                // Move to the next city if we have enough fuel
                int newFuelLeft = fuelLeft - fuelNeeded;
                if (totalCost < dist[nextCity][newFuelLeft]) {
                    dist[nextCity][newFuelLeft] = totalCost;
                    pq.push({totalCost, nextCity, newFuelLeft});
                }
            }
        }

        // Refuel at the current city if there is a fuel station
        if (fuelPrices[currentCity] != INF) {
            int refuelCost = (C - fuelLeft) * fuelPrices[currentCity]; // Refuel to full
            if (totalCost + refuelCost < dist[currentCity][C]) {
                dist[currentCity][C] = totalCost + refuelCost;
                pq.push({totalCost + refuelCost, currentCity, C});
            }
        }
    }
    
    return -1; // If no path is found
}

int main() {
    int N, M, S;
    cin >> N >> M >> S;
    
    int C;
    cin >> C;
    
    graph.resize(N + 1);
    fuelPrices.assign(N + 1, INF);
    
    // Input roads
    for (int i = 0; i < M; ++i) {
        int X, Y, G;
        cin >> X >> Y >> G;
        graph[X].push_back({Y, G});
        graph[Y].push_back({X, G});
    }
    
    // Input fuel stations
    for (int i = 0; i < S; ++i) {
        int city, price;
        cin >> city >> price;
        fuelPrices[city] = price;
    }
    
    // Start and end cities
    int A, B;
    cin >> A >> B;
    
    // Call the dijkstra function to get the minimum cost
    int result = dijkstra(N, M, C, A, B);
    
    if (result == -1) {
        cout << "No possible path" << endl;
    } else {
        cout << result << endl;
    }
    
    return 0;
}