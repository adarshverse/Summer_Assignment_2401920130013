// Decode String

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int>st;
        stack<string>ss;
        string curr = "";
        int n = 0;
        for (char c:s) {
            if (isdigit(c)) {
                n = n*10+(c-'0');
            }
            else if (c == '[') {
                st.push(n);
                ss.push(curr);
                n = 0;
                curr = "";
            }
            else if (c ==']') {
                int k = st.top();
            st.pop();
                string prev = ss.top();
            ss.pop();
                string temp = "";
                for (int i = 0; i < k; i++) {
                    temp += curr;
                }
            curr = prev + temp;
            }
            else {
            curr += c;
            }
        }
        return curr;
    }
};