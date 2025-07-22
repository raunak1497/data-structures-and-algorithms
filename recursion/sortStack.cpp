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

void insert(stack<int>& s,int val){
    if(s.size()== 0 || s.top()<=val){
        s.push(val);
        return;
    }
    int temp = s.top();
    s.pop();
    insert(s,val);
    s.push(temp);
    return;
}
void sortStack(stack<int>& s){
    if(s.size()==1){
        return;
    }
    int val = s.top();
    s.pop();
    sortStack(s);
    insert(s,val);
    return;
}
int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,temp;
    cin >> n;
    stack<int> s;
    FOR(i, n){
        cin >>temp;
        s.push(temp);
    }
    sortStack(s);
    FOR(i, n){
        cout<<s.top()<<" ";
        s.pop();
    }
        
    return 0;
}