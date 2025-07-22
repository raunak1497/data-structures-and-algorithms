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

bool dfsUtil(int node,int parent,vector<vector<int>>& adj,vector<bool>& visited){
    visited[node] = true;
    for(auto i : adj[node]){
        if(!visited[i]){
           if(dfsUtil(i,node,adj,visited))
               return true;
        }
        else if( i!= parent){
            return true;
        }
        
    }
    return false;
}
void addEdge(vector<vector<int> >& adj,int u, int v) 
{
    adj[u].push_back(v);
    adj[v].push_back(u); // Undirected Graph
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    // Adjacency list representation of the graph
    vector<vector<int> > adj(n);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 0, 3);
    addEdge(adj, 4, 5);
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(dfsUtil(i,-1,adj,visited)){
                return true;
            }
        }
    }
    return 0;
}