class Solution {
   public:
    int recurse(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int rob = nums[i] + recurse(nums, i + 2, dp);
        int skip = recurse(nums, i + 1, dp);

        return dp[i] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return recurse(nums, 0, dp);
    }
};