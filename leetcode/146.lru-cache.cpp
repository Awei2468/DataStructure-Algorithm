/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
private:
    int size;
    list<pair<int,int>> l;
    unordered_map<int, list<pair<int,int>>::iterator> ump;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        auto iter = ump.find(key);
        if (iter == ump.end()) return -1;
        l.splice(l.begin(), l, iter->second);
        return iter->second->second;
    }
    
    void put(int key, int value) {
        auto iter = ump.find(key);
        if (iter != ump.end()) l.erase(iter->second);
        l.push_front({key,value});
        ump[key] = l.begin();
        if (ump.size() > size) {
            int k = l.rbegin()->first;
            l.pop_back();
            ump.erase(k);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

