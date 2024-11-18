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

vector<vector<int>> subsets(vector<int>& nums) {
       int n = nums.size();
       vector<vector<int>> v;
       vector<int> vo;
       v.push_back(vo);
        for(int num=0;num<(1<<n);num++){
            vector<int> vi;
            for(int i=0;i<n;i++){
                if(num & (1<<i)){
                    vi.push_back(nums[i]);
                }
            }
            if(vi.size()>0){
                v.push_back(vi);
            }
        }
        return v;
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll a[n];
    FOR(i, n)
        cin >> a[i];
    vector<vector<int>> v;
    // v = subsets()
    return 0;
}