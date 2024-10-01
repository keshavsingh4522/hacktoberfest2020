#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q, l;
    cin>>n>>q;
    int **arr = new int*[n];
    for(int a=0; a<n; a++){
        cin>>l;
        arr[a] = new int[l];
        for(int k=0; k<l; k++){
            cin>>arr[a][k];
        }
    }
    int i,j;
    for(int a=0; a<q; a++){
        cin>>i>>j;
        cout<<arr[i][j]<<endl;
    }
    return 0;
}
