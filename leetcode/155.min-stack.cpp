/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int val) {
        S.push(val);
        if (val < Min) {
            Min = val;
            S_aux.push(val);
        }
        else {
            S_aux.push(Min);
        }
    }
    
    void pop() {
        S.pop();
        S_aux.pop();
        if (S.empty())
            Min = INT_MAX;
        else
            Min = S_aux.top();
    }
    
    int top() {
        return S.top();
    }
    
    int getMin() {
        return S_aux.top();
    }

private:
    stack<int> S, S_aux;
    int Min = INT_MAX;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

