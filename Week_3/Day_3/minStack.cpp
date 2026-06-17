// Min Stack

#include<iostream>
#include<stack>

using namespace std;

class MinStack {
public:
    stack<int> st;
    stack<int> helper;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if (helper.size() == 0 || helper.top() > value) helper.push(value);
        else helper.push(helper.top());
    }
    
    void pop() {
        st.pop();
        helper.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return helper.top();
    }
};

