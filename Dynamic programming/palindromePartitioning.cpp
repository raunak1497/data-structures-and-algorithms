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
//function to check if the given string is palindrome
bool isPalindrome(string s, int i, int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

//recursive
// int palindromicPartition(string s, int i, int j){
//     if(i>=j){
//         return 0;
//     }
//     if(isPalindrome(s,i,j))
//         return 0;
//     else{
//         int ans = INT_MAX,temp;
//         for(int k=i;k<j;k++){
//             temp = palindromicPartition(s,i,k) + palindromicPartition(s,k+1,j)+1;
//             ans = min(temp,ans);
//         }
//         return ans;
//     }
// }

//memoization
// int palindromicPartition(string s, int i, int j){
//     if(i>=j){
//         return dp[i][j] = 0;
//     }
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     if(isPalindrome(s,i,j))
//         return dp[i][j] = 0;
//     else{
//         int ans = INT_MAX,temp;
//         for(int k=i;k<j;k++ ){
//             temp = palindromicPartition(s,i,k) + palindromicPartition(s,k+1,j)+1;
//             ans = min(ans,temp);
//         }
//         return dp[i][j] = ans;
//     }
// }

//bottom up
int palindromicPartition(string s, int i, int j){
    if(i>=j){
        return dp[i][j] = 0;
    }

    if(isPalindrome(s,i,j)){
        return dp[i][j] = 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ans = INT_MAX;
    for(int k=i;k<j;k++){
        int left,right,temp;
        if(dp[i][k]!=-1){
            left = dp[i][k];
        }
        else{
            dp[i][k] = palindromicPartition(s,i,k);
            left = dp[i][k];
        }

        if(dp[k+1][j]!=-1){
            right = dp[k+1][j];
        }
        else{
            dp[k+1][j] = palindromicPartition(s,k+1,j);
            right = dp[k+1][j];
        }
        temp = 1+ left+right;
        ans = min(ans,temp);
    }

    return dp[i][j]=ans;
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin>>s;
    n = s.length();
    memset(dp,-1,sizeof(dp));
    cout<<palindromicPartition(s,0,n-1)<<endl;;
}