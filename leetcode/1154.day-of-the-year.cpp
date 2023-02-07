/*
 * @lc app=leetcode id=1154 lang=cpp
 *
 * [1154] Day of the Year
 */

// @lc code=start
class Solution {
public:
    int dayOfYear(string date) {
        int year = 0, month = 0, day = 0, cnt = 0;
        bool LeapYear = false;
        int tmp = 1000;
        for (int i = 0; i < date.size(); ++i) {
            if (i < 4) {
                year += (tmp * (date[i]-'0'));
                tmp /= 10;
            }
            else if (i == 4) {
                tmp = 10;
            }
            else if (i < 7) {
                month += (tmp * (date[i]-'0'));
                tmp /= 10;
            }
            else if (i == 7) {
                tmp = 10;
            }
            else {
                day += (tmp * (date[i]-'0'));
                tmp /= 10;
            }
        }

        if (!(year % 4) || (!(year % 100) && !(year % 400)))
            LeapYear = true;
        
        month--;
        while (month > 0) {
            switch (month) {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    cnt += 31;
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    cnt += 30;
                    break;
                default :  //2
                    if (LeapYear) cnt += 29;
                    else cnt += 28;
                    break;
            }
            --month;
        }
        cnt += day;
        return cnt;
    }
};
// @lc code=end

