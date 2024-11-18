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
int longestPalindromicSubsequence(string s){
    int n = s.size();
        string s2 = s;
        reverse(s2.begin(),s2.end());
        vector<vector<int> >dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n+1;i++){
            dp[i][0]=0;
        }

        for(int j=0;j<n+1;j++){
            dp[0][j]=0;
        }

        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[i-1]==s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return n-dp[n][n];
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    int n,m;
    string x;
    cin>>x;
    n = x.size();
    cout<<longestPalindromicSubsequence(x)<<endl;
    return 0;
}