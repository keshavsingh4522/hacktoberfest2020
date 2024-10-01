#include<bits/stdc++.h>
using namespace std;
/*

 Algortithm for converting Infix to Postfix expression

 1.) If Operand
    print it
2.)  If '('
    push to the stack
3.)  If ')'
    pop from the stack and print unitl '(' is found
4.)  If operator
   pop from the stack and print until an operator with less precedence is found

 */

int main()
{
   string s;
   cout<<"Enter the infix expression :";
   cin>>s;
   string netstring;
   stack<string> st;
   for(int i=0;i<s.length();i++)
   {
       if(s[i]<='z'&& s[i]>='a' || s[i]<='Z' && s[i]>='A')
       {
           netstring+=s[i];
       }
       else if(s[i]=='(')
       {
           st.push("(");
       }
       else if(s[i]==')')
       {
           while(s[i]!='(')
           {
               netstring+=s[i];
               st.pop();
           }
       }
       else
       {
           
       }
   }


  return 0;

}