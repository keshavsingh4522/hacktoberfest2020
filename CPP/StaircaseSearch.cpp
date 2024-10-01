//Staircase search for 2D Sorted Arrays - Only takes O(n) time.
#include<bits/stdc++.h>

using namespace std;

void stairCaseSearch(vector<vector<int>> arr, int n, int el) {
    int i=0, j=n-1;
    while(i<n && j>=0) {
        if(el==arr[i][j]) {
            cout<<"Found at row = "<<i+1<<" and column = "<<j+1;
            return ;
        } else if(el<arr[i][j])
            j--;
        else if(el>arr[i][j])
            i++;
    }
    cout<<"Not found";
    return;
}
int main() {
    int n, el;
    cin>>n>>el;
	vector<vector<int>> arr(n, vector<int> (n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>arr[i][j];
        }
    }
    stairCaseSearch(arr,n,el);
	return 0;
}
