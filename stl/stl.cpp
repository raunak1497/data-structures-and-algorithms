#include<iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <unordered_map>
// #include<bits/stdc++.h>
using namespace std;

//comparator function
bool f(int x,int y){
    return x>y;
}
void vectorDemo(){
    // Vector
    vector<int> A = {11,19,13,4};
    cout<<A[1]<<endl;
    sort(A.begin(),A.end()); //O(nlogn)
    cout<<A[1]<<endl;
    bool present = binary_search(A.begin(),A.end(),11); //O(logn)
    if(present)
        cout<<"It's present"<<endl;

    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(123);
    present = binary_search(A.begin(),A.end(),100);
   
   //getb the first 100
    auto it = lower_bound(A.begin(),A.end(),100); //>=
    vector<int>:: iterator it2 = upper_bound(A.begin(),A.end(),100); //>
    cout<<*it<<" "<<*it2<<endl;

    //sort in reverse order
    sort(A.begin(),A.end(),f);
    vector<int>:: iterator it3;
    for(int x: A){  
        cout<<x<<" ";
    }

}

void setDemo(){
    set<int> S;
    S.insert(1);
    S.insert(2);
    S.insert(-1);
    S.insert(-10);

    for(int x: S){
        cout<<x<<" ";
    }

    //-10 -1 1 2
    auto it = S.find(-1);
    if(it == S.end()){
        cout<<"Not present"<<endl;
    }
    else{
        cout<<"Present in set"<<endl;
    }

    auto it2 = S.lower_bound(-1); //>=
    auto it3 = S.upper_bound(0); //<
    cout<<*it2<<" "<<*it3;
}

void mapDemo(){
    map<int,int> m;
    m[1]= 100;
    m[2] =-1;
    m[3] = 200;
    m[100003] = 1;

    map<char,int> cnt;
    string x = "Raunak Singh";
    for(char c: x){
        cnt[c]++;
    }
    cout<<cnt['a'];
}

void uMapDemo(){
    map<char,int> m;
    unordered_map<char,int> u;
    string name = "Raunak Singh";
    for(char c: name){
        m[c]++; //nlog(n)
    }
    for(char c : name){
        u[c]++; //O(n)
    }
}

void powerSTL(){
    //add interval [x,y]
    // add [2,3]
    // add[10,20]
    // add[30,400]
    // add[399,450]
    // give me the interval 13
    set <pair<int,int>> S;
    S.insert({2,3});
    S.insert({10,20});
    S.insert({30,400});
    S.insert({399,450});

    int point = 13;
    auto it = S.upper_bound({point,INT_MAX}); 
    if(it == S.begin()){
        cout<<"Not found"<<endl;
        return;
    }
    it--;
    pair<int,int> current = *it;
    if(current.first<=point && current.second>=point){
        cout<<"it belongs to the interval ["<<current.first<<","<<current.second<<"]"<<endl;
    }else{
        cout<<"Not found"<<endl;
    }
}

int main(){
    // pair <int,int> p = {1,3};
    // cout<<p.first<<endl;
    // vectorDemo();
    // setDemo();
    // mapDemo();
    // powerSTL();
    uMapDemo();

    return 0;
}