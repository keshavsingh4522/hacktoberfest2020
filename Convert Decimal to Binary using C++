#include<iostream>
using namespace std;
int main()
{
    int decimalNum, binaryNum[20], i=0;
    cout<<"Enter the Decimal Number: ";
    cin>>decimalNum;
    while(decimalNum!=0)
    {
        binaryNum[i] = decimalNum%2;
        i++;
        decimalNum = decimalNum/2;
    }
    cout<<"\nEquivalent Binary Value: ";
    for(i=(i-1); i>=0; i--)
        cout<<binaryNum[i];
    cout<<endl;
    return 0;
}
