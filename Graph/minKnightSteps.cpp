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

int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos,int n){
    vector<vector<bool>> visited(n+1,vector<bool>(n+1,false));
    vector<vector<int>> dir = {{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2}};
    queue<vector<int>> q;
    visited[knightPos[0]][knightPos[1]] = true;
    q.push(knightPos);
    int steps = 0;
    while(!q.empty()){
        int length = q.size();
        for(int i=0;i<length;i++){
            vector<int> curr = q.front();
            q.pop();
            if(curr==targetPos){
                return steps;
            }
            for(auto& d: dir){
                int new_x = curr[0] + d[0];
                int new_y = curr[1] + d[1];
                vector<int> next = {new_x,new_y};
                if(new_x>=1 && new_x<=n && new_y>=1 && new_y<=n && !visited[new_x][new_y]){
                    visited[new_x][new_y] = true;
                    q.push(next);
                }
            }
            steps++;
        }
        return -1;
    }
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll a[n];
    FOR(i, n)
        cin >> a[i];
    return 0;
}