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

void allPerm(int z, int o,int n,string op,vector<string>& ans){
    if(op.size()==n){
        ans.push_back(op);
        return;
    }
    if(o>0){
        allPerm(z,o+1,n,op+'1',ans);
    }
    if(o>z){
         allPerm(z+1,o,n,op+'0',ans);
    }
    return;
    
}
vector<string> NBitBinary(int n)
{
    vector<string> ans;
    allPerm(0,1,n,"1",ans);
    return ans;
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> ans;
    ans = NBitBinary(n);
    for(string s : ans){
        cout<<s<<endl;
    }
    return 0;
}