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

// void permute(string &s,int start,int k,string & ans){
//     if(start == s.size() || k == 0 ){
//         ans = max(ans,s);
//         return;
//     }

//     char maxVal = s[start];
//     for(int j=start+1;j<s.size();j++){
//         maxVal = max(maxVal,s[j]);
//     }
//     for(int i=start+1;i<s.size();i++){
//         if(s[i]>s[start] && s[i]==maxVal){
//             swap(s[start],s[i]);
//             if(s.compare(ans)>0){
//                 ans = s;
//             }
//             permute(s,start+1,k-1,ans);
//             swap(s[start],s[i]);
//         }
//     }

//     permute(s,start+1,k,ans);
// }

void permute(string &s,int start,int k,string& ans){
    if(start == s.size() || k == 0 ){
        ans = max(ans,s);
        return;
    }

    char maxVal = s[start];
    for(int j=start+1;j<s.size();j++){
        maxVal = max(maxVal,s[j]);
    }
    if(s[start]==maxVal){
        permute(s,start+1,k,ans);
        return;
    }
    
    for(int i=start+1;i<s.size();i++){
        if(s[i]==maxVal){
            swap(s[start],s[i]);
            if(s.compare(ans)>0){
                ans = s;
            }
            permute(s,start+1,k-1,ans);
            swap(s[i],s[start]);
        }
    }
}
int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int k;
    cin>>k;
    string ans="";
    permute(s,0,k,ans);
    cout<<ans<<endl;
    return 0;
}