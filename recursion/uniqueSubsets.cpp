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

void allSubsets(int index, vector<int>& input,vector<int> & output, set<vector<int>>& v) {
    if(input.size()==index){
        v.insert(output);
        return;
    }
    vector<int> op1 = output;
    vector<int> op2 = output;

    op1.push_back(input[index]);
    allSubsets(index+1,input,op1,v);
    allSubsets(index+1,input,op2,v);

    return;

}
vector<vector<int> > uniqueSubsets(vector<int> arr)
{
    sort(arr.begin(),arr.end());
    set<vector<int>> v;
    vector<int> output;
    allSubsets(0,arr,output,v);
    vector<vector<int> > ans;
    for(vector<int> v1 : v){
        ans.push_back(v1);
    }
    return ans;
}

int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,temp;
    cin>>n;
    vector<int> input(n);
    FOR(i,n){
        cin>>input[i];
    }
    vector<vector<int>> ans;
    ans = uniqueSubsets(input);
    for (const auto& subset : ans) { // Loop through each subset
        for (int num : subset) {    // Loop through each element in the subset
            cout << num << " ";
        }
        cout << endl; // Newline after each subset
    }
    return 0;
}