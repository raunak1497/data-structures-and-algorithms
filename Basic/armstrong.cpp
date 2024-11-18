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

int armstrong(int A) {
    vector<int> a;
    int rem,dup = A;
    while(A){
        rem = A%10;
        a.push_back(rem);
        A=A/10;
    } 
    int n = a.size();
    int sum = 0;
    for(int i =0;i<n;i++){
        sum += pow(a[i],n);
    }
    cout<<sum<<endl;
    if(sum == dup){
        return 1;
    }
    return 0;
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,t;
    cin >> N;
    int result = armstrong(N);
    cout<<result<<endl;
    return 0;
}