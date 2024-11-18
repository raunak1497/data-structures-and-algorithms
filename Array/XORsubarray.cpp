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

//Bruteforce Soln
// int solve(int* a, int n, int b) {
//     int count = 0;
//     // int n  = a.size();
//     for(int i=0;i<n;i++){
//         int temp = 0;
//         for(int j = i;j<n;j++){
//             temp = temp^a[j];
//             if(temp==b){
//                 count++;
//             }
//         }
//     }
//     return count;
// }

int solve(int* a, int n, int b) {
    int count = 0;
    // int n  = a.size();
    map<int,int> mp;
    int curr = 0;
    for(int i=0;i<n;i++){
        curr = curr^a[i];
        if(curr == b){
            count++;
        }
        int temp = curr^b;
        if(mp[temp]>0){
            count+=mp[temp];
        }
        mp[curr]++;
    }
    return count;
}
int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n;
    int a[n];
    FOR(i, n)
        cin >> a[i];
    cin>>k;
    cout<<solve(a,n,k)<<endl;
    return 0;
}