/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*//BFS
        vector<vector<int>> record(numCourses);
        vector<int> degree(numCourses, 0);
        for (auto &p : prerequisites)  //build table
            record[p[1]].push_back(p[0]);
        for (vector<int> &v : record) {  //count every course degree
            for (int &t : v)
                degree[t]++;
        }
        for (int i = 0; i < numCourses; ++i) {
            int j = 0;
            for (; j < numCourses; ++j) {
                if (!degree[j]) break;
            }
            if (j == numCourses) return false;
            degree[j]--;
            for (int &t : record[j])
                degree[t]--;
        }
        return true;
        */
        //DFS
        vector<vector<int>> record(numCourses);
        vector<bool> todo(numCourses, false), done(numCourses, false);
        for (auto &p : prerequisites)  //build table
            record[p[1]].push_back(p[0]);
        for (int i = 0; i < numCourses; ++i) {  //DFS
            if (!acyclic(record, todo, done, i))
                return false;
        }
        return true;
    }
    bool acyclic(vector<vector<int>> &record, vector<bool> &todo, vector<bool> &done, int c) {
        if (todo[c]) return false;
        if (done[c]) return true;
        todo[c] = done[c] = true;
        for (int &v : record[c]) {
            if (!acyclic(record, todo, done, v))
                return false;
        }
        todo[c] = false;
        return true;
    }
};
// @lc code=end

