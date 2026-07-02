class Solution {
public:
    int recurse(vector<int>& nums, int i, int n, vector<int>& dp) {
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int rob = nums[i] + recurse(nums, i + 2, n, dp);
        int skip = recurse(nums, i + 1, n, dp);
        return dp[i] = max(rob, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        return max(
            recurse(nums, 0, n - 1, dp1), 
            recurse(nums, 1, n, dp2)      
        );
    }
};