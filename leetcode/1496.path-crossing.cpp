/*
 * @lc app=leetcode id=1496 lang=cpp
 *
 * [1496] Path Crossing
 */

// @lc code=start
class Solution {
public:
    bool isPathCrossing(string path) {
        map <pair<int,int>,int> M;
        M[{0,0}] = 1;
        //M[make_pair(0,0)] = 1;
        int x = 0, y = 0;
        for (char c : path) {
            switch (c) {
                case 'E':
                    x++;
                    break;
                case 'W':
                    x--;
                    break;
                case 'S':
                    y--;
                    break;
                default:  //N
                    y++;
                    break;
            }
            if (M.count({x,y}))
                return true;
            else
                M[{x,y}] = 1;
                //M[make_pair(x,y)] = 1;
        }
        return false;
    }
};
// @lc code=end

