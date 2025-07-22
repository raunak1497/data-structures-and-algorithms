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

vector<int>  lps(string p){
    int n = p.size();
    vector<int> lps(n, 0);
    int len = 0; //
    lps[0] = 0;
    int i=1;
    while(i < n){
        if(p[i] == p[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len!=0){
                len = lps[len-1];
            }else{
                i++;
            }
        }
    }
    return lps;
}
bool isMatch(string s,string p){
    vector<int> l = lps(p);
    int i=0,j=0;
    int n = s.size();
    int m = p.size();
    bool found = false;
    
    while(i<n && j<m){
        if(s[i] == p[j]){
            i++;
            j++;
        }
        
        if(j==m){
            cout<<"Pattern found at index "<<i-j<<endl;
            found = true;
            j = l[j-1];
        }
        else if(i<n && s[i] != p[j]){
            if(j!= 0){
                j = l[j-1];
            }else{
                i++;
            }
        }
    }
    return found;
}
int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s,p;
    cin>>s>>p;
    cout<<isMatch(s,p)<<endl;
    return 0;
}