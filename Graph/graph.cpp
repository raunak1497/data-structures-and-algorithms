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

 //adjacency list
// void print_graph(vector<vector<int> > adj){
   
//     for(int i=1;i<adj.size();i++){
//         cout<<"Node "<<i<<", Neighbours ";
//         for(int j=1;j<adj[i].size();j++){
//             if(adj[i][j]==1){
//                 cout<<j<<" ";
//             }
//         }
//         cout<<endl;
//     }
// }

//adj matrix
void print_graph(unordered_map<int , vector<int> > graph){
   
    for(auto x : graph){
        cout<<"Node "<<x.first<<", Neighbours ";
        for(auto node : x.second){
            cout<<node<<" ";
        }
        cout<<endl;
    }
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int> > edgeList = {{1,2},{2,3},{3,4},{4,2},{1,3}};
    
    int n;
    cin >> n;
    // Adjacency Matrix representation of the graph
    vector<vector<int> > adj(n,vector<int>(n,0));
    for(int i=0;i<edgeList.size();i++){
        int a  = edgeList[i][0];
        int b = edgeList[i][1];
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    // print_graph(adj);

    // Adjacency List representation of the graph
    unordered_map<int , vector<int> > graph;
    for(int i=0;i<edgeList.size();i++){
        int a  = edgeList[i][0];
        int b = edgeList[i][1];
       graph[a].push_back(b);
       graph[b].push_back(a);
    }
     print_graph(graph);
    return 0;
}