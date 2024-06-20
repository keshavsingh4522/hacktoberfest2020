#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int max = 0;
    for (int i = 0; i < n; i++){
        cin>>arr[i];
        if(arr[i] > max)
            max = arr[i];
    }
    int sum = 0; int flag = 0;
    for (int i = 0; i < n; i++){
        if (arr[i]==max)
            continue;
        for (int j = i; j < n; j++){
            if(arr[j]==max)
                continue;
            sum += arr[j];
        }
        if(sum == max){
            flag = 1;
            break;
        }
        else
            sum=0;
    }
    if(flag==1)
        cout<<"True";
    else
        cout<<"False";
}
