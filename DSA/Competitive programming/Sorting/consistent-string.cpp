#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,sum,min_sum;
    string st;
    char alphabets[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    cout<<"Enter the number strings: ";
    cin>>n;

    while(n--) {
        cin>>st;
        min_sum = 999;
        for(char letter: alphabets) {
            if(st[1] == '\0') {
                min_sum=0;
                break;
            }
            sum=0;
            for(int i=0; st[i] != '\0'; i++) {
                if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
                    if(st[i] == letter) {
                        sum+=0;
                    } else if(st[i] == 'a' || st[i] == 'e' || st[i] == 'i' || st[i] == 'o' || st[i] == 'u') {
                        sum+=2;
                    } else {
                        sum+=1;
                    }
                } else {
                    if(st[i] == letter) {
                        sum+=0;
                    } else if(st[i] == 'a' || st[i] == 'e' || st[i] == 'i' || st[i] == 'o' || st[i] == 'u') {
                        sum+=1;
                    } else {
                        sum+=2;
                    }
                }
            }

            if(sum<min_sum)
                min_sum=sum;
        }

        cout<<min_sum<<endl;
    }
}
