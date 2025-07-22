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

int len(string s,int i,int j){
        if(i>j){
            return 0;
        }
        while(i>=0 && j<s.size() && s[i]==s[j]){
                i--;
                j++;
        }
        return j-i-1;
    }
string longestPalindrome(string s) {
        int n = s.length();
        if(n==1){
            return s;
        }
        int start = 0;
        int end = 0;
        for(int i=0;i<n;i++){
            int a = len(s,i,i);
            int b = len(s,i,i+1);
            int length = max(a,b);
            if(length >end - start +1){
                start = i - ((length-1)/2);
                end = i + (length/2);
            }
        }
        return s.substr(start,end-start+1);
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
    return 0;
}