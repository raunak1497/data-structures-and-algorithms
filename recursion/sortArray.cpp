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
void insert(vector<int>& v,int val){
    if(v.size()==0 || v[v.size()-1] <= val){
        v.push_back(val);
        return;
    }
    int temp = v[v.size()-1];
    v.pop_back();
    insert(v,val);
    v.push_back(temp); 
    return;
}
void sort(vector<int>& v){
    if(v.size()==1){
        return; 
    }
    int val = v[v.size()-1];
    v.pop_back();
    sort(v);
    insert(v,val);
    return;
}
int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll a[n];
    vector<int> v(n);
    FOR(i, n)
        cin >> v[i];
    sort(v);
    FOR(i, n)
        cout<<v[i]<<" ";
    return 0;
}