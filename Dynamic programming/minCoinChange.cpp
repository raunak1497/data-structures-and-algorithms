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

// int minCoinChange(int amount, int coins[],int n) {
//     //    int n = coins.size();
//         // int dp[1001][1001] = {-1};
//          vector<vector<unsigned long long> >dp(n+1,vector<unsigned long long>(amount+1,-1));
//         int inf = INT_MAX;

//         for(int j=0;j<amount+1;j++){
//             dp[0][j] = inf-1;
//         }

//         for(int i=0;i<n+1;i++){
//             dp[i][0]= 0;
//         }

//         for(int i=1;i<n+1;i++){
//             for(int j=1;j<amount+1;j++){
//                 dp[i][j] = -1;
//             }
//         }
//         for(int j=0;j<amount+1;j++){
//                if(j%coins[0]==0){
//                   dp[1][j] = j/coins[0];
//                }
//                else{
//                 dp[1][j] = inf-1;
//                }
           
//         }
//         for(int i=2;i<n+1;i++){
//             for(int j=1;j<amount+1;j++){
//                 if(coins[i-1]<=j){
//                     dp[i][j] = min(1 + dp[i][j-coins[i-1]] , dp[i-1][j]);
//                 }
//                 else{
//                     dp[i][j] = dp[i-1][j];
//                 }
//             }
//         }
//         if(dp[n][amount] == inf-1){
//             return -1;
//         }
//         else{
//             return dp[n][amount];
//         }
//     }

int minCoinChange(int amount, int coins[],int n) {
    int inf = INT_MAX - 1;
    int dp[amount+1];
    for(int j=0;j<=amount;j++){
        dp[j]=inf;
    }
    dp[0] = 0;

    for(int i=0;i<n;i++){
        int coin = coins[i];
        for(int j=coin;j<=amount;j++){
            dp[j] = min(1+dp[j-coin], dp[j]);
        }
    }

    return dp[amount] == inf ? -1 : dp[amount];
}
int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,amount;
    cin >> n;
    int a[n];
    FOR(i, n)
        cin >> a[i];
    cin>>amount;
    cout<<minCoinChange(amount,a,n)<<endl;
    return 0;
}