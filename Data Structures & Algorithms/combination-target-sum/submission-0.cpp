class Solution {
   public:
    vector<int> s;
    vector<vector<int>> result;
    void backtrack(vector<int>& nums, int i, int target) {
        if (target == 0) {
            result.push_back(s);
            return;
        }
        if (i == nums.size()) return;
        // Pick
        if (nums[i] <= target) {
            s.push_back(nums[i]);
            backtrack(nums, i, target - nums[i]);
            s.pop_back();
        }
        // Skip
        backtrack(nums, i + 1, target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, target);
        return result;
    }
};
