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

vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int> ans;
        for(int num=0;num<(1<<n);num++){
            int sum = 0;
            for(int i=0;i<n;i++){
                if(num&(1<<i)){
                    sum+=arr[i];
                }
            }
            ans.push_back(sum);
        }
        return ans;
}


int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,a;
    cin >> n;
    vector<int> v;
    vector<int> ans;
    FOR(i, n){
        cin>>a;
        v.push_back(a);
    }
    ans = subsetSums(v,n);
    FOR(i,n){
        cout<<ans[i]<<" ";
    }
    return 0;
}