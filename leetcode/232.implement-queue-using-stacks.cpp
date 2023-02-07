/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        S1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int y;
        stack<int> S2;
        while (!S1.empty()) {
            S2.push(S1.top());
            S1.pop();
        }
        y = S2.top();
        S2.pop();
        while (!S2.empty()) {
            S1.push(S2.top());
            S2.pop();
        }
        return y;
    }
    
    /** Get the front element. */
    int peek() {
        int y;
        stack<int> S2;
        while (!S1.empty()) {
            S2.push(S1.top());
            S1.pop();
        }
        y = S2.top();
        while (!S2.empty()) {
            S1.push(S2.top());
            S2.pop();
        }
        return y;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return S1.empty();
    }
private:
    stack<int> S1;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

