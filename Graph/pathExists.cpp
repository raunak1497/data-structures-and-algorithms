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

void dfs(vector<vector<int>>& adj,vector<bool>& visited,int s){
        visited[s] = true;
        
        for(auto x : adj[s]){
            if(!visited[x]){
                visited[x] = true;
                dfs(adj,visited,x);
            }
        }

}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int> > edgeList = {{1,2},{2,3},{3,4},{4,2},{1,3}};

    // Adjacency List representation of the graph
    unordered_map<int , vector<int> > graph;
    for(int i=0;i<edgeList.size();i++){
        int a  = edgeList[i][0];
        int b = edgeList[i][1];
       graph[a].push_back(b);
       graph[b].push_back(a);
    }
    int n = edgeList.size();
    vector<bool> visited(n,false);
    dfs(adj,visited,source);

    return visited[destination];
    return 0;
}