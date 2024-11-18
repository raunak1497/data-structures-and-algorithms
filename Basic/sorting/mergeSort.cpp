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

void merge(int a[],int l,int mid,int r){
    int i=l,j=mid+1,index=0;
    int size = r-l+1;
    int temp[size];
    while(i<=mid && j<=r){
        if(a[i]<a[j]){
            temp[index] = a[i];
            i++;
        }
        else{
            temp[index] = a[j];
            j++;
        }
        index++;
    }
    if(i>mid){
        while(j<=r){
            temp[index] = a[j];
            j++;
            index++;
        }
    }
    if(j>r){
        while(i<=mid){
            temp[index] = a[i];
            i++;
            index++;
        }
    }
    for(int x=0;x<index;x++){
        a[l+x] = temp[x];
    }
}

void mergeSort(int a[],int l,int r){
    if(l>=r){
        return;
    }
    int mid = (l+r)/2;
    mergeSort(a,l,mid);
    mergeSort(a,mid+1,r);
    merge(a,l,mid,r);
    
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    FOR(i, n)
        cin >> a[i];
    mergeSort(a,0,n-1);
    FOR(i,n){
        cout<<a[i]<<" ";
    }
    return 0;
}