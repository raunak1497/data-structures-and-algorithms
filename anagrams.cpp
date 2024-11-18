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

vector<vector<string>> findAnagrams(vector<string> words, vector<string> queries){
    unordered_map<string,vector<string> > mp;
    sort(words.begin(),words.end());

    for(const auto &word : words){
        string key = word;
        sort(key.begin(),key.end());
        mp[key].push_back(word);
    }

    vector<vector<string>> ans;
    for(auto &query : queries){
        sort(query.begin(),query.end());
        ans.push_back(mp[query]);
    }

    return ans;
}

int main() {
    vector<string> words = {"peach", "cat", "cheap", "tac", "duel", "tca"};
    vector<string> queries = {"act", "phcae"};

    vector<vector<string>> anagrams = findAnagrams(words, queries);

    for (const auto& group : anagrams) {
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
