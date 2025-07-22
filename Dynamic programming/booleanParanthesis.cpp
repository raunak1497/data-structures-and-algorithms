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

unordered_map<string, ll> mp;
int solve(string s, int i,int j, bool isTrue){
    if(i>j){
        return 0;
    }
    if(i == j){
        if(isTrue){
            return s[i] == 'T' ? 1 : 0;
        }else{
            return s[i] == 'F' ? 1 : 0;
        }
    }

    string temp = to_string(i) +' ' + to_string(j) + ' ' + to_string(isTrue);
    if(mp.find(temp) != mp.end()){
        return mp[temp];
    }

    int ans = 0;
    for(int k = i+1;k<j;k=k+2){
        int leftTrue = solve(s,i,k-1,true);
        int leftFalse = solve(s,i,k-1,false);
        int rightTrue =  solve(s,k+1,j,true);
        int rightFalse =  solve(s,k+1,j,false);

        if(s[k] == '^'){
            ans+= isTrue ? leftTrue*rightFalse + leftFalse*rightTrue :
                leftTrue*rightTrue + leftFalse*rightFalse;
        }
        else if(s[k] == '&'){
            ans+= isTrue ? leftTrue*rightTrue : leftTrue*rightFalse + leftFalse*rightTrue
                + leftFalse*rightFalse;
        }
        else{
            ans+= isTrue ? leftTrue*rightFalse + leftFalse*rightTrue
                + rightTrue*leftTrue  : leftFalse*rightFalse;
        }
    }

    return mp[temp]=  ans;
}
int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    mp.clear();
    string s;
    cin >> s;
    int n = s.length();
    // int n;
    // cin >> n;
    // ll a[n];
    // FOR(i, n)
    //     cin >> a[i];
    cout<<solve(s,0,n-1,true)<<endl;
    return 0;
}