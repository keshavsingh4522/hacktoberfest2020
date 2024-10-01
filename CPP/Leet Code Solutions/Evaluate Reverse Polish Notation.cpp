class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<long long int> st;
        for(string i : tokens )
        {
            if(i == "+" || i == "-" ||i == "*" ||i == "/" )   //If the token is an operator
            {
                long long int s = st.top();                   // Current Integer data or the second operand
                st.pop();                                     // Removing the values from the stack
                long long int p = st.top();                   // First Operand
                st.pop();                                     // Removing the values from the stack
                
                if(i == "+")                                  //If operator is +
                {
                    st.push(s+p);
                }
                else if( i == "-")                            // If operator is -
                {
                    st.push(p - s);
                }
                else if( i == "*")                            // If operator is *
                {
                    st.push(s * p);
                }
                else                                         //If operator is /
                {
                    st.push(p / s);
                }
            }
            else                                             // If the data is a number
            {
                st.push(stoll(i));                           // Push the numeric value into the stack
            }
        }
        return st.top();
    }
};
