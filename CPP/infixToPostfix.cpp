#include<iostream>
#include <stack>

using namespace std;

int precedence(char ch){

    switch(ch){

    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

bool isOperand(char ch){
    return ( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') );
}

int infixToPostfix(string exp){

    stack<char> s;
    string ans;
    int k=0;
    for(int i=0;exp[i]!='\0';i++){
        char ch = exp[i];
        if(ch == '('){
            s.push(ch);
           }
        else if(isOperand(ch)){
            ans[k++] = ch;
        }
        else if(ch == ')'){
            while(!s.empty() && s.top() != '('){
                ans[k++] = s.top();
                s.pop();
            }
            if(s.empty() && s.top() != '('){
                return -1;
               }
            s.pop();
        }
        else{
            while(!s.empty() && precedence(ch)<=precedence(s.top())){
                ans[k++] = s.top();
                s.pop();
            }
            s.push(ch);
        }

        while(!s.empty()){
            ans[k++] = s.top();
            s.pop();
        }
        ans[k] = '\0';
        cout<<ans;

    }

}

int main()
{

    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);

}
