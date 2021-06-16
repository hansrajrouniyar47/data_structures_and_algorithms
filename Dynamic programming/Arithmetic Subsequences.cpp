
/*
https://binarysearch.com/problems/Arithmetic-Subsequences


*/


int solve(vector<int>& nums) {
    int n = nums.size(), res = 0;

    vector<unordered_map<long long, int>> dp(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            long long diff = (long long)nums[i] - nums[j];
            res += dp[j][diff];
            dp[i][diff] += 1 + dp[j][diff];
        }
    }

    return res;
}