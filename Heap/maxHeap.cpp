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

// vector<int> minHeap(vector<int> a,int n){
//     for(int i)
// }
// void swap(int* a, int* b){
//     int temp  = *a;
//     a = b;
//     temp  = *a;
// }

void heapify(int a[],int n,int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && a[l]>a[largest]){
        largest = l;
    }
    if(r<n && a[r]>a[largest]){
        largest = r;
    }
    if(largest!=i){
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }

}
void buildHeap(int a[],int n){
    int idx = n/2 - 1;
    for(int i=idx;i>=0;i--){
        heapify(a,n,i);
    }
}

int extractMax(int a[],int n){
    int max = a[0];
    a[0]=a[n-1];
    heapify(a,n-1,0);
    return max;
}
int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n]; 
    FOR(i, n){
        cin>>a[i];
    }
    buildHeap(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"Max element is : "<<extractMax(a,n)<<endl;
    n--;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}