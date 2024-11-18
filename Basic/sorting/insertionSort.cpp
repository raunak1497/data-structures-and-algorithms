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

void insertionSort(ll a[],int n){
    int index = 0;
    for(int i =1;i<n; i++){
        int min = INT_MAX;
        for(int j=i;j>0;j--){
            if(a[j-1]>a[j]){
                swap(a[j-1],a[j]);
            }
        }
    }
    FOR(i,n){
        cout<<a[i]<<" ";
    }

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
    insertionSort(a,n);
    return 0;
}