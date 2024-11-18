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
int compute(string str){
    int n = str.length();
    int dp[n+1];
    dp[0]=1;
    vector<int> last(256,-1);
    for(int i=1;i<=n;i++){
        dp[i] = 2*dp[i-1];
        
        if(last[str[i-1]]!= -1){
            dp[i] = dp[i] - dp[last[str[i-1]]];
        }
        last[str[i-1]] = (i-1);
    }
    
    return dp[n];
    }
string betterString(string str1, string str2){
        int a = compute(str1), b = compute(str2);
        if(a<b)
            return str2;
        return str1;
}
int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str1,str2;
    cin>>str1;
    cin>>str2;
    cout<<betterString(str1,str2)<<endl;
    return 0;
}