// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;

// #define total_Station 6
// #define total_Line 2


// int Assembly(int a[][total_Station],int t[][total_Station],int e[total_Line],int x[total_Line]){

//     int t1[total_Station];
//     int t2[total_Station];
//     t1[0] = e[0] + a[0][0];
//     t2[0] = e[1] + a[1][0]; 

//    for(int i=1;i<total_Station;i++){
//        t1[i] = min(t1[i-1] + a[0][i],t2[i-1]  + t[0][i] + a[1][i]);
//        t2[i] = min(t2[i-1] + a[1][i],t1[i-1]  + t[1][i] + a[0][i]);
//    }
   
//    return min(t1[total_Station-1] + x[0],t2[total_Station-1] + x[1]);
// }

// int main(){

//     int a[][total_Station] = {
//                                 {7,9,3,4,8,4},
//                                 {8,5,6,4,5,7}
//                              };

//     int t[][total_Station] = {
//                    {0,2,3,1,3,4},
//                    {0,2,1,2,2,1}
//                 };
//     int e[] = {2,4};
//     int x[] = {3,2};

//     cout<<"The Minimum time taken is :  "<<Assembly(a,t,e,x);
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;
#define n 6
#define m 5

int min(int a, int b){
    return a < b ? a : b;
}

int carAssembly(int a[][n],int t[][n],int *e, int *x){

    int l1[n], l2[n], i;
    
    l1[0] = e[0] + a[0][0];     
    l2[0] = e[1] + a[1][0];
    vector<string>v1,v2;
    v1.push_back("Line-1");
    v2.push_back("Line-2");
    for (i = 1; i < n; ++i){
        l1[i] = min(l1[i - 1] + a[0][i],l2[i - 1] + t[1][i] + a[0][i]);
        min(l1[i - 1] + a[0][i],l2[i - 1] + t[1][i] + a[0][i])==l1[i - 1] + a[0][i]?v1.push_back("Line-1"):v1.push_back("Line-2");    
        l2[i] = min(l2[i - 1] + a[1][i],l1[i - 1] + t[0][i] + a[1][i]);
        min(l2[i - 1] + a[1][i],l1[i - 1] + t[0][i] + a[1][i])==l2[i - 1] + a[1][i]?v2.push_back("Line-2"):v2.push_back("Line-1");
    }

    for(auto x:l1)
        cout<<x<<' ';
    cout<<'\n';

    for(auto x:l2)
        cout<<x<<' ';
    cout<<'\n';
    
    if(min(l1[n - 1] + x[0],l2[n - 1] + x[1])==l1[n - 1] + x[0]){
        int cnt=1;
        for(auto x:v1)
            cout<<x<<" & Station-"<<cnt++<<" ->\n";     
        cout<<"Line-1 & Station-"<<cnt++<<'\n';
    }else{
        int cnt=1;
        for(auto x:v2)
            cout<<x<<" & Station-"<<cnt++<<"->\n";
        cout<<"Line-2 & Station-"<<cnt++<<'\n';
    }

    return min(l1[n - 1] + x[0],l2[n - 1] + x[1]);
}

int main()
{
    int a[][n] = {{7,9,3,4,8,4},
                 {8,5,6,4,5,7}};
    int t[][n] = {{0,2,3,1,3,4},
                 {0,2,1,2,2,1}};
    int e[] = {2, 4};
    int x[] = {3, 2};

    cout << "Total minimum distance : " <<carAssembly(a, t, e, x);
    
}
