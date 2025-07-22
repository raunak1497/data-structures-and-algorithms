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

int dp[1001][1001];
//Topdown
// int longestCommonSubstring(string x,string y, int n, int m){
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=m;j++){
//             if(i==0 || j==0){
//                 dp[i][j]=0;
//             }
//         }
//     }
//     int ans = 0;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//            if(x[i-1]==y[j-1]){
//             dp[i][j] = 1 + dp[i-1][j-1];
//            }
//            else{
//             dp[i][j] = 0;
//            }
//            ans = max(ans,dp[i][j]);
//         }
//     }

//     return ans;
// }

int longestCommonSubstring(string x,string y, int n, int m){
    if(n>m){
        return longestCommonSubstring(y,x,m,n);
    }

    int dp[m+1];
    for(int i=0;i<=m;i++){
        dp[i]=0;
    }
    int prev,ans=0;
    for(int i=1;i<=n;i++){
        prev=0;
        for (int j = 1; j<=m; j++)
        {
            int temp = dp[j];
            if(x[i-1]==y[j-1]){
                dp[j] = prev +1;
                ans = max(ans,dp[j]);
            }else{
                dp[j] = 0;
            }
            prev = temp;
        }
    }
    return ans;
}


int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    int n,m;
    string x,y;
    cin>>x;
    cin>>y;
    n = x.size();
    m = y.size();
    cout<<longestCommonSubstring(x,y,n,m)<<endl;
    return 0;
}