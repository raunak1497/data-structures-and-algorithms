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
//Memoization
// int knapSack(int w, int wt[], int val[], int n) 
//     {
//        if(n==0 || w ==0){
//            return dp[0][0]=0;
//        }
//        if(dp[n][w]!=-1){
//            return dp[n][w];
//        }
//         if(wt[n-1]<=w){
//             return dp[n][w] = max( val[n-1]+knapSack(w-wt[n-1],wt,val,n-1) , //selecting the weight
//             knapSack(w,wt,val,n-1));  //not selecting the weight
//         }
//         else if(wt[n-1]>w){
//             return knapSack(w,wt,val,n-1);    
//         }
// }

//Topdown
int knapSack(int w, int wt[], int val[], int n) 
{
       for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
       } 

       for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j){
                dp[i][j] = max((val[i-1]+ dp[i-1][j-wt[i-1]]), dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
       } 
        return dp[n][w];
}


int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,w;
    cin >> n;
    int wt[n];
    int val[n];
    FOR(i, n)
        cin >> wt[i];
    FOR(i, n)
        cin >> val[i];
    cin>>w;
    memset(dp,-1,sizeof(dp));
    int ans = knapSack(w,wt,val,n);
    cout<<dp[n][w]<<endl;
    return 0;
}