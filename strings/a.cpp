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

    vector<string> generateallString(int n,int k,char* s,vector<string> ans){
        vector<string> b;
        cout<<n<<endl;
        if(n==k){
            string a;
            for(int i=0;i<n;i++){
                a+=s[i];
            }
            cout<<a<<" ";
            ans.push_back(a);
            b = ans;
        }
        if(s[k-1]==1){
            s[k]='0';
            ans = generateallString(n,k+1,s,ans);
            s[k]='1';
            ans = generateallString(n,k+1,s,ans);
        }
        if(s[k-1]==0){
            s[k]='1';
            ans = generateallString(n,k+1,s,ans);
        }
        return b;
    }
    vector<string> validStrings(int n) {
        cout<<n<<endl;
        vector<string> ans;
        char s[n];
        s[0] = '0';
        ans = generateallString(n,1,s,ans);
        s[0] = '1';
        ans = generateallString(n,1,s,ans);
        for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
        return ans;
    }

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> a;
    a = validStrings(n);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    return 0;
}