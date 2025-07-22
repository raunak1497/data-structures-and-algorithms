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
 
bool dp[1001][1001];

// //Topdown
// int subsetSum(int sum, int arr[],int n) 
// {
//        for(int j=0;j<sum+1;j++){
//             dp[0][j] = false;
//        }
//        for(int i=0;i<n+1;i++){
//         dp[i][0] = true;
//        }

//        for(int i=1;i<n+1;i++){
//         for(int j=1;j<sum+1;j++){
//             if(arr[i-1]<=j){
//                 dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
//             }
//             else{
//                 dp[i][j] = dp[i-1][j];
//             }
//         }
//        }

//        return dp[n][sum];
// }

//Topdown 1D
int subsetSum(int sum, int arr[],int n) 
{
       bool dp1[sum+1];
       memset(dp1,false,sizeof(dp1));
       dp1[0]=true;

       for(int i = 0;i<n;i++){
        int num = arr[i];
        for(int j=sum;j>=num;j--){
            dp1[j] = dp1[j] || dp1[j-num];
        }
       }
       
    return dp1[sum+1];

}
// bool isSubsetSum(vector<int>arr, int sum){
//         int n = arr.size();
//         vector<vector<bool>>t(n+1, vector<bool>(sum+1, 0));
//         for(int i = 0; i < n+1; i++){
//             for(int j = 0; j < sum+1; j++){
//                 if(j==0) t[i][j] = 1;
//             }
//         }
//         for(int i = 1; i < n+1; i++){
//             for(int j = 1; j < sum+1; j++){
//                 if(arr[i-1]<=j) t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
//                 else t[i][j] = t[i-1][j];
//             }
//         }
        
//         return t[n][sum];
        
//     }

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,sum;
    memset(dp,false,sizeof(dp));
    cin >> n;
    int arr[n];
    int val[n];
    FOR(i, n)
        cin >> arr[i];
    cin>>sum;
    if(subsetSum(sum,arr,n))
        cout<<"Subset sum is present"<<endl;
    else
        cout<<"Subset sum is not present"<<endl;

    return 0;
}