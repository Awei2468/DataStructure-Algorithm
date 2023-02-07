/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        //map <int , char> M;
        string res;
        int temp;
        /*
        for (int i = 1; i <= 26; ++i) 
            M[i] = 'A' + i - 1;
        */
        
        while (columnNumber > 26) {
            temp = columnNumber % 26;
            if (!temp) {
                temp = 26;
                res.insert(0, 1, 'A'+temp-1);
                columnNumber /= 26;
                columnNumber -= 1;
                continue;
            }
            res.insert(0, 1, 'A'+temp-1);
            columnNumber /= 26;
        }
        res.insert(0, 1, 'A'+columnNumber-1);
        return res;
    }
};
// @lc code=end

