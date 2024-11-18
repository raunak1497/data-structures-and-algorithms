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

/* Iterative */
int lower_bound(int a[],int l,int r, int target){
            int ans;
            while(l<=r){
                int mid = l + (r-l)/2;
                if(a[mid] == target){
                    while(a[mid] == target){
                        mid--;
                    }
                    ans = mid+1;
                    return ans;
                }
                else if(target< a[mid]){
                    if(a[mid-1]< target && target< a[mid]){
                        ans = mid;
                        return ans;
                    }else{
                        r = mid-1;
                    }
                }
                else{
                    if(a[mid]< target && target< a[mid+1]){
                        ans = mid+1;
                        return ans;
                    }else{
                        l = mid+1;
                    }
                }
            }
            return ans;
    }

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,target,ans;
    cin >> n;
    int a[n];
    FOR(i, n)
        cin >> a[i];
    cin>>target;
    if(target>a[n-1]){
            ans = n;
            return ans;
        }
        if(target<a[0]){
            ans = 0;
            return ans;
        }
    ans = lower_bound(a,0,n-1,target);
    cout<<ans<<endl;
    return 0;
}