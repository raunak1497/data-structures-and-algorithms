#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
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

void solve(int index,string& s,vector<string> &ans,string output, unordered_map<string,int>& mp){
    if(index == s.size()){
        ans.push_back(output);
        return;
    }
    
    for(int i=index;i<s.size();i++){
        string op = s.substr(index,i-index+1);
        if(mp.find(op) != mp.end()){
            string new_current = output.empty() ? op : output + " " + op;
            solve(i + 1, s, ans, new_current, mp);
        }
    }
}

vector<string> wordBreak(string s,vector<string>& dict){
    unordered_map<string,int> mp;
    vector<string> ans;
    for(int i=0;i<dict.size();i++){
            mp[dict[i]]++;
    }
    solve(0,s,ans,"",mp);
    return ans;
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    vector<string> dict;
    wordBreak(s,dict);
    return 0;
}