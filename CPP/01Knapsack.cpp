#include <iostream>

using namespace std;

int knapsack(int *w, int *v, int capacity, int n, int **ans){
    if(n == 0 || capacity <= 0){
        return 0;
    }

    if(ans[n][capacity] != -1){
        return ans[n][capacity];
    }
    int output;
    if(w[0] > capacity){
        output =  knapsack(w + 1, v + 1, capacity, n - 1, ans);
    }
    else{
        int a = knapsack(w + 1, v + 1, capacity, n - 1, ans);
        int b = knapsack(w + 1, v + 1, capacity - w[0], n - 1, ans) + v[0];
        output = max(a, b);
    }
    
    ans[n][capacity] = output;
    return ans[n][capacity];
}

int knapsackDP(int *w, int *v, int capacity, int n){
    int **ans = new int*[n + 1];
    for(int i = 0; i <= n; i++){
        ans[i] = new int[capacity + 1];
    }
    for(int i = 0; i <= n ; i++){
        for(int j = 0; j <= capacity; j++){
            if(i == 0 || j == 0){
                ans[i][j] = 0;
            }
            else if(w[i - 1] > j){
                ans[i][j] = ans[i - 1][j];
            }
            else{
                ans[i][j] = max(v[i - 1] + ans[i - 1][j - w[i - 1]], ans[i - 1][j]);
            }
        }
    }

    return ans[n][capacity];
}

int main(){

    int n;cin>>n;
    int w[n], v[n];
    for(int i = 0; i < n; i++){
        cin>>w[i];
    }
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    int capacity;cin>>capacity;

    int **ans = new int*[n + 1];
    for(int i = 0 ; i <= n; i++){
        ans[i] = new int[capacity + 1];
        for(int j = 0; j <= capacity; j++){
            ans[i][j] = -1;
        }
    }

    cout<<knapsackDP(w, v, capacity, n);


    return 0;
}
