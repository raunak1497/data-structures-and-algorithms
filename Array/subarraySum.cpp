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

// O(N^2) soln
// int subarraySum(vector<int>& a, int k) {
//         int n = a.size();
//         vector<int> sum;
//         sum.push_back(0);
//         int count = 0;
//         for(int i=0;i<n;i++){
//             sum.push_back(sum[i] + a[i]);
//         }
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n+1;j++){
//                 if(sum[j]-sum[i] == k){
//                     // cout<<i<<" "<<j;
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }

int subarraySum(vector<int>& a, int k){
    map<long long,int> mp;
    long long sum  = 0;
    int result = 0;
    int n = a.size();
    mp[0] = 1;
    for(int i = 0;i<n;i++){
        sum+=a[i];
        long long rem = sum - k;
        if(mp.find(rem) != mp.end()){
            result+=mp[rem];
        }
        mp[sum] += 1;
    }
    return result;
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
        int N,x,k;
        cin >> N;
        vector <int> a;
        FOR(i, N){
            cin >> x;
            a.push_back(x);
        }
        cin>>k;
        int ans = subarraySum(a,k);
        cout<<ans<<endl;
        return 0;
}
    
