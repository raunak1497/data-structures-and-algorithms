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

void subset(int arr[],int n,int sum){
    for(int j=0;j<sum+1;j++){
        dp[0][j] = false; 
    }

    for(int i=0;i<n+1;i++){
        dp[i][0] = true; 
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}

//Topdown
int minSubsetSum(int arr[],int n,int sum){
    subset(arr,n,sum);
    int min = INT_MAX;
    for(int i=0;i<(sum+1)/2;i++){
        if(dp[n][i] && abs(sum-2*i)<min){
            min = abs(sum-2*i);
        }
    }
    return min;
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,sum=0;
    memset(dp,-1,sizeof(dp));
    cin >> n;
    int arr[n];
    int val[n];
    FOR(i, n){
         cin >> arr[i];
         sum+=arr[i];
    }
    cout<<minSubsetSum(arr,n,sum)<<endl;
    return 0;
}