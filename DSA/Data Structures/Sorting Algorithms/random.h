#pragma once
#include <bits/stdc++.h>
using namespace std;

void populate(vector<int> &v, int n){
    v.clear();
    srand(time(NULL));
    for(int i=0; i<n; ++i){
        v.push_back(rand()%100);
    }
}

void print(vector<int> &v, string desc="Array"){
    cout<<desc<<" : ";
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}