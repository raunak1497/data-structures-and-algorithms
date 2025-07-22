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

void allPermutation(string s, string op,int index, set<string>& ans){
    if(s.size()==index){
        ans.insert(op);
        return;
    }
    string op1,op2;
    if(s[index]>64 && s[index]<91){
        char c = s[index]+32;
        op1 = op+c;
        op2 = op+s[index];
    }
    
    if(s[index]>96 && s[index]<123){
        char c = s[index]-32;
        op1 = op+c;
        op2 = op+s[index];
    }
    allPermutation(s,op2,index+1,ans);
    allPermutation(s,op1,index+1,ans);
    
    return;
}
vector<string> permutationCaseChange(string s) {
    // Code Here
    set<string> v;
    string op = "";
    allPermutation(s,op,0,v);
    vector<string> ans;
    for(string s1 : v){
        ans.push_back(s1);
    }
    return ans;
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    vector<string> ans;
    cin >> s;
    ans = permutationCaseChange(s);
    for(string s1 : ans){
        cout<<s1<<endl;
    }
    return 0;
}