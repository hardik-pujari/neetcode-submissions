class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void backtrack(vector<int>& nums, int start, int target) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates
            if (i > start && nums[i] == nums[i - 1])
                continue;
            // No point continuing (array is sorted)
            if (nums[i] > target)
                break;
            curr.push_back(nums[i]);
            backtrack(nums, i + 1, target - nums[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target);
        return ans;
    }
};