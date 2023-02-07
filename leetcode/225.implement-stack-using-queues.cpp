/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        Q1.push(x);
        for (int i = 0; i < Q1.size()-1; ++i) {
            Q1.push(Q1.front());
            Q1.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        x = Q1.front();
        Q1.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return Q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return Q1.empty();
    }
private:
    queue <int> Q1;
    int x;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

