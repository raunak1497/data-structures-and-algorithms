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

/* Recursive */
// int binary_search(ll a[],int l,int r, int target){
//     int mid = l + (r-l)/2;
//             if(r>=l && target == a[mid]){
//                 return mid;
//             }
//             else if(r>=l && target < a[mid]){
//                 return binary_search(a,l,mid-1,target);
//             }
//             else if(r>=l && target> a[mid]){
//                 return binary_search(a,mid+1,r,target);
//             }
//             return -1;
// }

/* Iterative */
int binary_search(ll a[],int l,int r, int target){
            while(l<=r){
                int mid = l + (r-l)/2;
                if(a[mid] == target){
                    return mid;
                }
                if(target< a[mid]){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            return -1;
    }

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,target;
    cin >> n;
    ll a[n];
    FOR(i, n)
        cin >> a[i];
    cin>>target;
    cout<<binary_search(a,0,n-1,target);
    return 0;
}