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

// int coinChangeSum(int amount, int coins[],int n) {
//     //    int n = coins.size();
//         // int dp[1001][1001] = {-1};
//         vector<vector<unsigned long long> >dp(n+1,vector<unsigned long long>(amount+1,-1));

//         for(int j=0;j<amount+1;j++){
//             dp[0][j] = 0;
//         }

//         for(int i=0;i<n+1;i++){
//             dp[i][0]= 1;
//         }

//         for(int i=1;i<n+1;i++){
//             for(int j=1;j<amount+1;j++){
//                 if(coins[i-1]<=j){
//                     dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
//                 }
//                 else{
//                     dp[i][j] = dp[i-1][j];
//                 }
//             }
//         }

//         return dp[n][amount]; 
//     }

int coinChangeSum(int sum, int coins[],int n){
    int dp[sum+1];
    dp[0]=1;
        
    for(int i = 0;i<n;i++){
        int coin = coins[i];
        for(int j=coin;j<=sum;j++){
            dp[j] += dp[j-coin];
        }  
    }
    return dp[sum];
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
    cout<<coinChangeSum(amount,a,n)<<endl;
    return 0;
}