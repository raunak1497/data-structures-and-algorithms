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

//recursive
// vector<string> permute(string ip,string op, vector<string> &v){
//     if(ip.size() == 0){
//         v.push_back(op);
//         return v;
//     }
//     unordered_set<char> mp;
//     for(int i=0;i<ip.size();i++){
//         if(mp.find(ip[i])== mp.end()){
//             mp.insert(ip[i]);
//             string newip = ip.substr(0,i) + ip.substr(i+1);
//             string newop = op + ip[i];
//             permute(newip,newop,v);
//         }
//     }
//     return v;
// }
vector<string> permute(string ip,string op, vector<string> &v){
    if(ip.size()==0){
        v.push_back(op);
        return v;
    }

    unordered_map<char,int> mp;
    for(int i=0;i<ip.size();i++){
        if(mp.find(ip[i])==mp.end()){
            mp[ip[i]]++;
            string newip = ip.substr(0,i) + ip.substr(i+1,ip.size());
            string newop = op + ip[i];
            permute(newip,newop,v);
        }
        
    }

    return v;
}
// //backtracking
void permute(string &s,int start, vector<string> &ans){
    if(start == s.size()-1){
        ans.push_back(s);
    }
    unordered_map<char,int> mp;
    for(int i=start;i<s.size();i++){
        if(mp.find(s[i])==mp.end()){
            mp[s[i]]++;
            swap(s[i],s[start]);
            permute(s,start+1,ans);
            swap(s[start],s[i]);
        }
        
    }
}
int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    vector<string> ans;
    // v = permute(s,"",ans);
    // set<string> ans;
    permute(s,0,ans);
    // vector<string> v(ans.begin(),ans.end());
     for (const string &perm : ans) {
        cout << perm << endl;
    }
    return 0;
}