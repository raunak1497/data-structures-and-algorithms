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

void dfs(int node,vector<int>& edges,vector<bool>& visited,vector<int>& path,int& ans){
    if(visited[node])
        return;
    visited[node] = true;
    int curr = edges[node];
    if(curr!=-1){
        if(!visited[curr]){
            path[curr]=path[node]+1;
            dfs(curr,edges,visited,path,ans);
        }
        if(path[curr]!=0){
            ans = max(ans,path[node]-path[curr]+1);
        }
    }
    path[node]=0;
}
int longestCycle(vector<int>& edges) {
    int n = edges.size();
    vector<bool> visited(n,false);
    vector<int> path(n,0);
    int ans = -1;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            path[i]=1;
            dfs(i,edges,visited,path,ans);
        }
    }
    return ans;
}

void addEdge(vector<vector<int> >& adj,int u, int v) 
{
    adj[u].push_back(v);
    // adj[v].push_back(u); // Undirected Graph
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i: n){
        cin>>a[i];
    }
    return longestCycle(a);
}