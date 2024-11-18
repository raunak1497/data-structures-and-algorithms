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

vector<string> v;
void generate(string s,int n,int l,int r){
        if(l<=r){
            if(l==n && r==n){
                v.push_back(s);
                return;
            }
            else if(l==n){
                generate(s+')',n,l,r+1);
            }
            else{
                generate(s+'(',n,l+1,r);
                generate(s+')',n,l,r+1);
            }
        }
        
    }

void generateParenthesis(int n) {
        string s = "";
        int l =0,r=0;
        generate(s,n,l,r);
        return;
    }

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    generateParenthesis(3);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}