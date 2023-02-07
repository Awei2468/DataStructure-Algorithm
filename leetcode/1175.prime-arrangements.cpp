/*
 * @lc app=leetcode id=1175 lang=cpp
 *
 * [1175] Prime Arrangements
 */

// @lc code=start
class Solution {
private:
    bool DP[100];
    int Mod = 1000000007;
public:
    Solution() {
        DP[0] = false;
        CheckPrime(100);
    }
    int numPrimeArrangements(int n) {
        if (n == 1) return 1;
        int prime = 0, ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (DP[i-1])
                ++prime;
        }
        ans = (Factorial(prime) * Factorial(n-prime)) % Mod;
        return ans;
    }
    void CheckPrime(int n) {
        for (int i = 2; i <= n; ++i) {
            bool chk = true;
            for (int j = 2; j*j <= i; ++j) {
                if (!(i % j)) {
                    DP[i-1] = false;
                    chk = false;
                    break;
                }
            }
            if (chk)
                DP[i-1] = true;
        }
    }
    unsigned long long Factorial(int n) {
        unsigned long long t = 1;
        while (n > 0) {
            t = (t*n) % Mod;
            --n;
        }
        return t;
    }
};
// @lc code=end

