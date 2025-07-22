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

vector<vector<string>> ans;

bool isPalindrome(string s){
    string r = s;
    reverse(r.begin(),r.end());
    return r == s;
}

void solve(string& s,int index, vector<string>&v){
    if(index == s.size()){
        ans.push_back(v);
        return;
    }

    for(int i=index;i<s.size();i++){
        string op = s.substr(index,i-index+1);
        if(isPalindrome(op)){
            v.push_back(op);
            solve(s,i+1,v);
            v.pop_back();
        }
    }
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    vector<string> v;
    solve(s,0,v);
    return 0;
}