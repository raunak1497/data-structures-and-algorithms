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

long long int floorSqrt(long long int n) 
{
    int l = 1,r=n;
    while(l<=r){
        long long int  mid = (l+r)/2;
        long long int val = mid*mid;
        if(val <= (long long)(n)){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return r;
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int n;
    cin >> n;
    cout<<floorSqrt(n)<<endl;
    return 0;
}