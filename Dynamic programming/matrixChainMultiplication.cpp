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

ll dp[1001][1001];
//Recursive Code
// int matrixChainMultiplication(ll a[],int i,int j){
//     if(i>=j){
//         return 0;
//     }
//     else{
//         int min = INT_MAX;
//         for(int k =i;k<=j-1;k++){
//             int temp = matrixChainMultiplication(a,i,k) + matrixChainMultiplication(a,k+1,j) + a[i-1]*a[k]*a[j];
//             if(temp<min)
//                 min = temp;
//         }
//         return min;
//     }
// }

//Memoization 
// int matrixChainMultiplication(ll a[],int i,int j){
//     if(i>=j){
//         return 0;
//     }
//     else{
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         else{
//             int min = INT_MAX;
//             for(int k =i;k<=j-1;k++){
//                 int temp = matrixChainMultiplication(a,i,k) + matrixChainMultiplication(a,k+1,j) + a[i-1]*a[k]*a[j];
//                 dp[i][j] = temp;
//                 if(temp<min)
//                     min = temp;
//             }
//             return min;
//         }
        
//     }
// }

//Top down
int matrixChainMultiplication(ll a[],int n){
    for(int i= 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i>=j || i==0)
                dp[i][j] = 0;
        }
    }

    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
            ll cost = INT_MAX;
            for(int k = i; k<=j-1; k++){
                cost = min((dp[i][k],dp[k+1][j]+ a[i-1]*a[k]*a[j]),cost);
            }
            dp[i][j]=cost;
        }
    }
    return dp[1][n-1];
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
    memset(dp,-1,sizeof(dp));
    // cout<<matrixChainMultiplication(a,1,n-1)<<endl;
    cout<<matrixChainMultiplication(a,n)<<endl;
    return 0;
}