#include <bits/stdc++.h>

using namespace std;

int main()
{
    char under[501];
    char camel[501];
    cin>>under;
    int i,j=0,len;
    len=strlen(under);
    for(i=0;i<len;i++){
        if(!isupper(under[i])){
            camel[j]=under[i];
            j++;
        }
        else{
            camel[j]='_';
            j++;
            camel[j]=tolower(under[i]);
            j++;
        }
    }
    camel[j]='\0';
    cout<<camel;

    return 0;
}

