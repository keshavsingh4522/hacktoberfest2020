#include <iostream>
#include <stack>
#include <queue>
using namespace std;
/**
 * 
 *  Aman Upadhyay
 *  Amity University Kolkata
 * 
*/
class Solution
{
    stack<char> mystack;
    queue<char> myqueue;

    public:
          void pushCharacter(char ch)
          {
              mystack.push(ch);
          }
          void enqueueCharacter(char ch)
          {
              myqueue.push(ch);
          }
          char popCharacter()
          {
              char top = mystack.top();
              mystack.pop();
              return top;
          }
          char dequeueCharacter()
          {
              char front = myqueue.front();
              myqueue.pop();
              return front;
          }
};

int main()
{
    string s;
    getline(cin, s);

    Solution obj;

    for (int i = 0; i < s.length(); i++)
    {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    bool isPalindrome = true;

    for (int i = 0; i < s.length()/2; i++)
    {
        if (obj.popCharacter() != obj.dequeueCharacter())
        {
            isPalindrome = false;
            break;
        }
        
    }
    if (isPalindrome)
    {
        cout << "The word, " << s << ", is a palindrome.";
    }
    else
    {
        cout << "The word, " << s << ", is not a palindrome.";
    }
    
    return 0;
}