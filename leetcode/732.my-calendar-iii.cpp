/*
 * @lc app=leetcode id=732 lang=cpp
 *
 * [732] My Calendar III
 */

// @lc code=start
class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        M1[start]++;
        M1[end]--;
        int cnt = 0;
        for (auto m : M1) {
            cnt += m.second;
            if (cnt > max)
                max = cnt;
        }
        return max;
    }

private:
    map <int,int> M1;
    int max = INT_MIN;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
// @lc code=end

