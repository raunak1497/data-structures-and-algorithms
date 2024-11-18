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

int search(int a[],int l,int r, int target) {
        int ans = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(a[mid] == target){
                ans = mid;
                return ans;
            }
            //left half is sorted
            if(a[l]<=a[mid]){
                if(a[l]<=target && target<=a[mid]){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            //right half is sorted
            else{
                if(a[mid]<=target && target<=a[r]){
                    l = mid+1;
                }else{
                    r = mid-1;
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
    ans = search(a,0,n-1,target);
    cout<<ans<<endl;
    return 0;
}