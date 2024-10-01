#include<iostream>
#include<vector>
#include <stdio.h>
#include<bits/stdc++.h>
#include<algorithm>
#include<cstring>
#include<set>
#include<string>
#include<math.h>
#include <iterator> 
 
using namespace std;
 
long long M=pow(10,9)+7;
 
main(){
    string s;
    cin>>s;
    string s1;
    char ch;
    int t=0;
    int k=0;
    sort(s.begin(),s.end());
    if(s.size()==1){
        cout<<s[0];
        exit(0);
    }
    if(s.size()%2==0){
    for(int i=0;i<s.size();i+=2){
        if(s[i]==s[i+1]){
            s1.push_back(s[i]);
        }
        else{
            t=-1;
            break;
        }
    }
    if(t!=-1){
    cout<<s1;
    reverse(s1.begin(),s1.end());
    cout<<s1;
    }
    else{
        cout<<"NO SOLUTION";
    }
    }
    else{
        for(int i=0;i<s.size();i+=2){
        if(s[i]==s[i+1]&&i!=s.size()-1){
            s1.push_back(s[i]);
        }
        else if(k==0&&i!=s.size()-1){
            ch=s[i];
            i=i-1;
            k++;
        }
        else if(i==s.size()-1){
            break;
        }
        else{
            t=-1;
            break;
        }
        }   
        if(k==0){
        ch=s[s.size()-1];
    }
    if(t!=-1){
    cout<<s1<<ch;
    reverse(s1.begin(),s1.end());
    cout<<s1;
    }
    else{
        cout<<"NO SOLUTION";
    }
    }
    
    
}