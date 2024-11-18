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

int maxSubArray(vector<int>& a) {
        int n = a.size();
        int currsum = 0;
        int max = 0;
        int l=0,r;
        for(int i=0;i<n;i++){
            currsum+=a[i];
            if(max<currsum){
                max =  currsum;
                r = i; //right index of subarray
            }
            if(currsum<0){
                currsum = 0;
                l=i; //left index of subarray
            }
        }
        if(l!=0){
            l++;
        }
        return max;
    }

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
        int N,x,k;
        cin >> N;
        vector <int> a;
        FOR(i, N){
            cin >> x;
            a.push_back(x);
        }
        int ans = maxSubArray(a);
        cout<<ans<<endl;
        return 0;
}
    
