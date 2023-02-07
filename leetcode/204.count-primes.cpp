/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        if (!n || n == 1) return 0;
        int res = 0;
        //vector<bool> prime(n-2, true);
        bool *prime = new bool[n]{};
        /*
        for (int k = 0; k < 10; ++k) {
            if (prime[k])
                cout << "T" << " ";
            else
                cout << "F" << " ";
        }
        */
        for (int i = 2; i < n; ++i) {
            if (prime[i]) continue;
            res++;
            for (int j = 2; i*j < n; ++j)
                prime[i*j] = true;
        }
        delete [] prime;
        return res;
    }
};
// @lc code=end

