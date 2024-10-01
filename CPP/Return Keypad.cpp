Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
The numbers and their corresponding codes are given below:
0: ""
1: ""
2: "abc"
3: "def"
4: "ghi"
5: "jkl"
6: "mno"
7: "pqrs"
8: "tuv"
9: "wxyz"
Return empty string for numbers 0 and 1.
Note:
1. The order of strings are not important.
2. The input number will have digits between: [2, 9].
Input Format :
First line of input will contain T number of test cases.
Each input consists of a single line containing an integer n.
Output Format :
For each test case, print all possible strings in different lines.
Constraints :
1 <= T <= 100
1 <= n <= 10^6
Sample Input:
1
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
   Code
   
   #include <iostream>
#include <string>

using namespace std;


int keypad(int num, string output[])
{
    string key[10] = { "", "", "abc", "def", "ghi", "jkl", "mno" ,"pqrs", "tuv", "wxyz"};
    if(num==0)
    {
        output[0]="";
        return 1;
    }
    int digit = num % 10;
    string smalloutput[1000];
    int count = keypad(num/10, smalloutput);
    string str=key[digit];
    int k=0;
    for(int i=0; i<str.length(); i++)
    {
    for(int j=0; j<count; j++)
    {
        output[k]=smalloutput[j]+str[i];
        k++;
    }
    }
    return k;
   
    
    
    
    

int main(){
    int t;
    cin >> t;
    while(t--)
    {
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    }
    return 0;
}
