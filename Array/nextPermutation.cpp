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

void nextPermutation(vector<int>& a) {
        int n = a.size();
        int p = -1;
        if(n<=1){
            return;
        }
        if(n==2){
            swap(a[0],a[1]);
            return;
        }

        for(int i=n-2;i>=0;i--){
            if(a[i]<a[i+1]){
                p = i;
                break;
            }
        }
        if(p == -1){
            reverse(a.begin(),a.end());
        }
        int min = INT_MAX,index;
        for(int i=p+1;i<n;i++){
            if((a[i]-a[p])> 0 && (a[i]-a[p])<=min){
                min = a[i]-a[p];
                index = i;
            }
        }
        swap(a[p],a[index]);
        reverse(a.begin()+p+1,a.end());
        return;
    }

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,b;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        cin>>b;
        a.push_back(b);
    }
    // FOR(i,n){
    //     cout<<a[i]<<" ";
    // }
    nextPermutation(a);
    FOR(i,n){
        cout<<a[i]<<" ";
    }
    return 0;
}