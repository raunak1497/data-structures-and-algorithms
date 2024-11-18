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

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack< pair<int,int> > st;
        int n = intervals.size();
        int a,b,c,d;
        sort(intervals.begin(),intervals.end());
        st.push({intervals[0][0],intervals[0][1]});
        for(int i=1;i<n;i++){
            pair<int,int> p;
            p = st.top();
            a = p.first;
            b = p.second;
            c = intervals[i][0];
            d = intervals[i][1];
            // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
            if(b == c){
                st.pop();
                st.push({a,d});
            }
            else if(c<b && d>b){
                st.pop();
                st.push({a,d});
            }
            else if(a==c){
                st.pop();
                st.push({a,d});
            }
            else if(a<c && b>d){
                st.pop();
                st.push({a,b});
            }
            else if(c>b){
                st.push({c,d});
            }
        }
        pair<int,int> p;
        p = st.top();
        a = p.first;
        b = p.second;
        // cout<<a<<" "<<b<<endl;
        // int m = st.size();
        // cout<<"The stack is "<<m<<endl;
        vector<vector<int>> v;
        int i=0;
        while(!st.empty()){
            pair<int,int> p;
            p = st.top();
            st.pop();
            a = p.first;
            b = p.second;
            vector<int> v1;
            v1.push_back(a);
            v1.push_back(b);
            v.push_back(v1); 
        } 
        reverse(v.begin(), v.end());
        return v;
    }

int main() 
{ 
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> vp(n, vector<int>(2));
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        vp[i][0] = a;
        vp[i][1] = b;
    }
    vector<vector<int>> v = merge(vp);
    cout<<v.size();
    // for(int i =0 ;i < vp.size();i++){
    //     cout<<v[i][0]<<"is"<<v[i][1]<<endl;
    // }
    return 0;
}