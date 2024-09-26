#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
    long int num=0,n=x;
    if (x<0 || (x!=0 && x%10==0)){
        return false;
    }
    else{
        while(n!=0){
            num=num*10+n%10;
            n=n/10;
        }
        return (x==num)?true:false;
    }        
}

int main(){
    int x;
    int result;
    cin>>x;
    result=isPalindrome(x);
    if (result==1){
        cout<<"Is Palindrome";
    }
    else{
        cout<<"Not a Palindrome";
    }
    return 0;
}