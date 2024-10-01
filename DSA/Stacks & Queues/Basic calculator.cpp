/*
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
 
Example 1:
Input: s = "1 + 1"
Output: 2
Example 2:
Input: s = " 2-1 + 2 "
Output: 3
Example 3:
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 
Constraints:
1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation.
'-' could be used as a unary operation and in this case, it will not be used directly after a +ve or -ve signs (will be inside parentheses).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.
*/
//main driver

#include <bits/stdc++.h>
using namespace std;

int calc(int a,int b,char op){
    if(op=='-')a-=b;
    else a+=b;
    return a;
}
int calculate(string s) {
    stack<int>so,sn;
    int n=s.size();
    for(int i=0;i<n;i++){
        char c=s[i];
        if(c>='0' && c<='9'){
            int nu=0;
            while(i<n && s[i]>='0' && s[i]<='9'){
                nu*=10;
                nu+=int(s[i]-'0');
                i++;
            }
            i--;
            if(sn.size()>0){
                if(so.top()=='('){
                    sn.push(nu);
                }
                else{
                    int tp=sn.top();
                    sn.pop();
                    sn.push(calc(tp,nu,so.top()));
                    so.pop();
                }
            }
            else{
                if(so.size()>0 && so.top()!='(' && so.top()!=')'){so.pop(),nu*=-1;}
                sn.push(nu);
            }
            // cout<<sn.top()<<" "<<so.size()<<endl;
        }
        else if(c!=' ' && c!=')'){
            so.push(c);
        }
        else if(c==')'){
            so.pop();
            if(sn.size()>1){
                int tp=sn.top();
                sn.pop();
                int tp2=sn.top();
                sn.pop();
                sn.push(calc(tp2,tp,so.top()));
                so.pop();
            }
            
        }
    }
    int sig=1;
    if(!so.empty())sig=-1;
    return sn.top()*sig;
}
int main(){
	int t;
	cin>>t;
	while(t-->0){
		string s;
		cin>>s;
		cout<<calculate(s);
	}
	return 0;
}
