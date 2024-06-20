#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "madam";

    int n = s.length(), flag = 1;
    
    for(int i = 0; i < n/2; i++){
        if(s[i] != s[n-i-1]){
            flag = 0;
            break;
        }
    }
    
    if(flag){
        cout << s << " is a Palindrome.\n";
    }
    else{
        cout << s << " is not a Palindrome.\n";
    }

    return 0;

}
