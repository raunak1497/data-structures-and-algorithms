#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

bool isReachable(int n, int k, const vector<vector<pair<int, int>>> &adj, int maxCost) {
    queue<pair<int, int>> q; // {node, depth}
    vector<bool> visited(n + 1, false);
    q.push({1, 0});
    visited[1] = true;

    while (!q.empty()) {
        auto [node, depth] = q.front();
        q.pop();

        if (node == n) return true;
        if (depth == k) continue;

        for (auto &[neighbor, cost] : adj[node]) {
            if (cost <= maxCost && !visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, depth + 1});
            }
        }
    }

    return false;
}

int getMinRepairCost(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight, int k) {
    int left = 0, right = *max_element(g_weight.begin(), g_weight.end()), answer = -1;

    // Build adjacency list
    vector<vector<pair<int, int>>> adj(g_nodes + 1);
    for (int i = 0; i < g_from.size(); ++i) {
        int u = g_from[i], v = g_to[i], w = g_weight[i];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Binary search on the cost
    while (left <= right) {
        int mid = (left + right) / 2;

        if (isReachable(g_nodes, k, adj, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return answer;
}

// Sample usage
int main() {
    int g_nodes = 4;
    int g_edges = 4;
    vector<int> g_from = {2,3,2,1};
    vector<int> g_to   = {3, 1,4,2};
    vector<int> g_weight = {6,4,5,2};
    int k = 3;

    int result = getMinRepairCost(g_nodes, g_from, g_to, g_weight, k);
    cout << "Minimum repair cost: " << result << endl;  // Expected: 8
    return 0;
}