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

void path(int x,int y,vector<vector<int>> &mat, string& route, vector<string>& ans){
    int n = mat.size();
    int m = mat[0].size();
    
    if(x == n-1 && y == m-1){
        ans.push_back(route);
        return;
    }
    
    vector<vector<int>> coordinates = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    vector<char> dir = {'D','L','U','R'};
    for(int i=0;i<4;i++){
        int new_x = x + coordinates[i][0];
        int new_y = y + coordinates[i][1];
        if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && mat[new_x][new_y] == 1 ){
            mat[new_x][new_y] = 0;
            route+= dir[i];
            path(new_x,new_y,mat,route,ans);
            route.pop_back();
            mat[new_x][new_y] = 1;
        }
        
    }
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,a;
    cin >> n >> m;
    vector<vector<int>> mat;
    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j=0;j<m;j++){
            cin>>a;
            v.push_back(a);
        }
        mat.push_back(v);
    }
    vector<string> ans;
    string route = "";
    if (mat[0][0] == 1) {
        mat[0][0] = 0; // Mark the starting cell as visited
        path(0, 0, mat, route, ans);
    }
    return 0;
}