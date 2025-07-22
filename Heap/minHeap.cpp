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

void heapify(ll a[],int n,int i){
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && a[left]<a[smallest]){
        smallest = left;
    }
    if(right<n && a[right]<a[smallest]){
        smallest = right;
    }
    if(smallest != i){
        swap(a[smallest],a[i]);
        heapify(a,n,smallest);
    }
}
void buildMinHeap(ll a[],int n){
    int idx = n/2-1;
    for(int i=idx;i>=0; i--){
        heapify(a,n,i);
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
    buildMinHeap(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}