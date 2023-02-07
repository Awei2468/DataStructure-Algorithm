/*
 * @lc app=leetcode id=381 lang=cpp
 *
 * [381] Insert Delete GetRandom O(1) - Duplicates allowed
 */

// @lc code=start
class RandomizedCollection {
private:
    unordered_map <int, unordered_set<int>> M;
    vector<int> record;

public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        M[val].insert(record.size());
        record.push_back(val);
        return M[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (!M[val].size()) return false;
        int idx = *M[val].begin();
        M[val].erase(idx);
        if (record.size() - 1 != idx) {
            int tmp = record.back();
            record[idx] = tmp;
            M[tmp].erase(record.size() - 1);
            M[tmp].insert(idx);
        }
        record.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return record[rand() % record.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

