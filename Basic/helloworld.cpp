#include<iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> arr_input(vector<int> arr, int n){
    int input;
    for(int i = 0;i<n;i++){
        cin>>input;
        arr.push_back(input);
    }
    return arr;
}

void arr_print(vector<int> arr, int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    cout<< "Hello, World!\n";
    int n;
    vector<int> arr;
    cin>>n;
    arr = arr_input(arr,n);
    arr_print(arr,n);
    return 0;
}
