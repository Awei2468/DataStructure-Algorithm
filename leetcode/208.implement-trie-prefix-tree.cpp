/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
/*
class Trie {
private:
    unordered_set<string> ust;
    unordered_set<string> pre_ust;
public:
    Trie() {
        
    }
    
    void insert(string word) {
        ust.insert(word);
        int len = word.size();
        for (int i = 0; i < len; ++i)
            pre_ust.insert(word.substr(0, i+1));
    }
    
    bool search(string word) {
        return ust.count(word);
    }
    
    bool startsWith(string prefix) {
        return pre_ust.count(prefix);
    }
};
*/
class TrieNode {
public:
    TrieNode *child[26];
    bool valid;
    TrieNode():valid(false) {
        for (int i = 0; i < 26; ++i)
            child[i] = nullptr;
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }  
    void insert(string word) {
        TrieNode *cur = root;
        int n = word.size();
        for (int i = 0; i < n; ++i) {
            if (!cur->child[word[i] - 'a']) {
                cur->child[word[i] - 'a'] = new TrieNode();
            }
            cur = cur->child[word[i] - 'a'];
        }
        cur->valid = true;
    }   
    bool search(string word) {
        TrieNode *cur = root;
        int n = word.size();
        for (int i = 0; i < n; ++i) {
            cur = cur->child[word[i] - 'a'];
            if (!cur) return false;
        }
        return cur->valid;
    }  
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        int n = prefix.size();
        for (int i = 0; i < n; ++i) {
            cur = cur->child[prefix[i] - 'a'];
            if (!cur) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

