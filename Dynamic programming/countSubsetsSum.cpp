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
int countSubsetSum(int k, int arr[],int n) 
{
    int count = 1;
    dp[0][0]=1;
	for(int i=0;i<n;i++){
		if(arr[i]==0){
			count*=2;
			dp[i+1][0] = count;
		}
		else{
			dp[i+1][0] = dp[i][0];
		}
	}
	// int mod = (int)1e9+7;

	for(int i=1;i<n+1;i++){
		for(int j=1;j<k+1;j++){
			if(arr[i-1]<=j){
				dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j]) % mod;
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][k];
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,sum;
    memset(dp,-1,sizeof(dp));
    cin >> n;
    int arr[n];
    int val[n];
    FOR(i, n)
        cin >> arr[i];
    cin>>sum;
    cout<<countSubsetSum(sum,arr,n)<<endl;
    return 0;
}