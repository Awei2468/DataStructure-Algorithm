/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 */

// @lc code=start
class MyCalendarTwo {
public:
    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
        M1[start]++;
        M1[end]--;
        int cnt = 0;
        for (auto m : M1) {
            cnt += m.second;
            if (cnt == 3) {
                M1[start]--;
                M1[end]++;
                return false;
            }
        }
        return true;
    }

private:
    map <int,int> M1;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

