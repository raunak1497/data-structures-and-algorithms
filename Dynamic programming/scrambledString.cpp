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
// #define mp make_pair

unordered_map<string, bool> mp;

bool scrambledString(string s, string t) {
    if(s == t) return true;
    if(s.length() != t.length()) return false;
    if(s.length() <= 1) return false;

    string key = s + " " + t;
    if(mp.find(key) != mp.end()) return mp[key];

    int n = s.length();
    bool flag = false;

    for(int i = 1; i < n; i++) {
        bool cond1 = scrambledString(s.substr(0,i), t.substr(n-i,i)) && 
                     scrambledString(s.substr(i,n-i), t.substr(0,n-i));
        
        bool cond2 = scrambledString(s.substr(0,i), t.substr(0,i)) && 
                     scrambledString(s.substr(i,n-i), t.substr(i,n-i));

        if(cond1 || cond2) {
            flag = true;
            break;
        }
    }

    return mp[key] = flag;
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    unordered_map<char, bool> mp;
    int n;
    n = s.size();
    cout<<scrambledString(s,t)<<endl;
    return 0;
}