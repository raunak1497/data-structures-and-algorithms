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

int dp[101][1001];
int eggDrop(int e, int f){
    if(f ==0 || f==1){
        return f;
    }
    if(e == 1){
        return f;
    }
    if(dp[e][f]!= -1)
        return dp[e][f];

    int mn = INT_MAX;
    int low = 1,high = f;
    while(low<=high){
        int mid = low + (high-low)/2;
        int lower = (dp[e-1][mid-1]!= -1)? dp[e-1][mid-1] : eggDrop(e-1,mid-1);
        int upper = (dp[e][f-mid]!= -1)? dp[e][f-mid] : eggDrop(e,f-mid);

        int temp = 1 + max(lower,upper);
        mn = min(mn,temp);

        if(lower< upper){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    return dp[e][f] = mn;
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int e,f;
    cin>>e>>f;
    memset(dp,-1,sizeof(dp));
    cout<<eggDrop(e,f)<<endl;
    return 0;
}