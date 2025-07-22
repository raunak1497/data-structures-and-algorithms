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

void solve(int len,int start,int n,vector<int>& ans,int num){
    if(len == n){
        ans.push_back(num);
        return;
    }
    
    for(int i = start;i<10;i++){
        num = num*10+i;
        solve(len+1,i+1,n,ans,num);
        num = num/10;
    }
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> ans;
    if(n==1){
        ans.push_back(0);
    }
    solve(0,1,n,ans,0);
    for(int num : ans){
        cout<<num<<" ";
    }
    return 0;
}