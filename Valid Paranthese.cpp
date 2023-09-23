/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

class Solution {
public:
    bool isValid(string s) {
       stack<char> st;
       for (int i=0; i<s.length(); i++) {
           char ch = s[i];
           if(ch == '(' || ch == '{' || ch == '['){
               st.push(ch);
           }
           else{
            // if a closing bracket then we compare with the top of the stack 
                // while comparing with top of stack we have 2 cases 
                // the stack can be empty or the stack is not empty 
               if(!st.empty()){
                   char top = st.top();
                   if ((ch == ')' && top == '(') || 
                        (ch == '}' && top == '{') ||
                        (ch == ']' && top == '[')) 
                        {
                            
                            st.pop() ;
                        }
                        else 
                        {
                            return false ; 
                        }
               }
               else{
                   return false;
               }
           }
       }
       if(st.empty()){
           return true;
       }
       return false;
    }
};
