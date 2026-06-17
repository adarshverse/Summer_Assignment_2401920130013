// Valid Parentheses

#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0;i < s.size();i++) {
            if (s[i] =='(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } 
            else {
                if ((s[i] ==')' || s[i] == ']' || s[i] == '}') && st.empty()) return false;
                else {
                    if ((s[i] == ')') && st.top() != '(') return false;
                    else if ((s[i] == ']') && st.top() != '[') return false;
                    else if ((s[i] == '}') && st.top() != '{') return false;
                    st.pop();
                }
            }
        }
        if (!st.empty()) return false;
        return true;
    }
};