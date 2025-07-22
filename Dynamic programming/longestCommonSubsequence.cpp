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

// int dp[1001][1001];
//recursive
// int longestCommonSubsequence(string x,string y, int n, int m){
//     if(n==0 || m==0){
//         return 0;
//     }

//     if(x[n-1]==y[m-1]){
//         return (1 + longestCommonSubsequence(x,y,n-1,m-1));
//     }
//     else{
//         return max (longestCommonSubsequence(x,y,n,m-1),longestCommonSubsequence(x,y,n-1,m));
//     }
// }

//Memoization
// int longestCommonSubsequence(string x,string y, int n, int m){
//     if(n==0 || m==0){
//        return dp[n][m]=0;
//     }

//     if(dp[n][m]!=-1){
//         return dp[n][m];
//     }
//     else{
//         if(x[n-1]==y[m-1]){
//             return dp[n][m] = (1 + longestCommonSubsequence(x,y,n-1,m-1));
//         }
//         else{
//             return dp[n][m] = max(longestCommonSubsequence(x,y,n,m-1),longestCommonSubsequence(x,y,n-1,m));
//         }
//     }
// }

//Topdown
// int longestCommonSubsequence(string x,string y, int n, int m){
//     memset(dp,-1,sizeof(dp));
//     for(int i=0;i<n+1;i++){
//         dp[i][0]=0;
//     }

//     for(int j=0;j<m+1;j++){
//         dp[0][j]=0;
//     }

//     for(int i=1;i<n+1;i++){
//         for(int j=1;j<m+1;j++){
//             if(x[i-1]==y[j-1]){
//                 dp[i][j]= 1 + dp[i-1][j-1];
//             }
//             else{
//                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//     }
//     return dp[n][m];
// }

int longestCommonSubsequence(string x,string y, int n, int m){
    if(n>m){
        return longestCommonSubsequence(y,x,m,n);
    }

    int dp[m+1];
    for(int i=0;i<=m;i++){
        dp[i]=0;
    }
    int prev;
    for(int i=1;i<=n;i++){
        prev=0;
        for (int j = 1; j<=m; j++)
        {
            int temp = dp[j];
            if(x[i-1]==y[j-1]){
                dp[j] = prev +1;
            }else{
                dp[j] = max(dp[j],dp[j-1]);
            }
            prev = temp;
        }
    }
    return dp[m];
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    string x,y;
    cin>>x;
    cin>>y;
    n = x.size();
    m = y.size();
    cout<<longestCommonSubsequence(x,y,n,m)<<endl;
    return 0;
}