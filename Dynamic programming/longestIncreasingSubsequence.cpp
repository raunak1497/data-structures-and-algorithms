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
int longestIncreasingSubsequence(ll a[],int n){
    vector<int>dp(n,1);
    int ans = INT_MIN;
    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(a[j]>a[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
       ans = max(ans,dp[i]);
    }
    return ans;
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
    cout<<longestIncreasingSubsequence(a,n)<<endl;
    return 0;
}