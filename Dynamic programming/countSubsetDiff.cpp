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

int countPartitions(int n, int diff, int arr[]) {
        // Code here
        memset(dp,-1,sizeof(dp));
        int total = 0;
        for(int i=0;i<n;i++){
            total+=arr[i];
        }
        int sum = (total+diff)/2;
        if((total+diff)%2 == 1 ){
            return 0;
        }
        else{
            dp[0][0] = 1;
            for(int i=1;i<n+1;i++){
                for(int j=0;j<sum+1;j++){
                    if(arr[i-1]<=j){
                        dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        return dp[n][sum];
        
    }

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,sum=0,diff;
    memset(dp,-1,sizeof(dp));
    cin >> n;
    cin>>diff;
    int arr[n];
    int val[n];
    FOR(i, n){
         cin >> arr[i];
         sum+=arr[i];
    }
    cout<<countPartitions(n,diff,arr)<<endl;
    return 0;
}