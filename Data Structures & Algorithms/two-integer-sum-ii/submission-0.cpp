class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result;
        int i = 0, j = n - 1;
        while (i < j) {
            if (nums[i] == nums[j]) i++;
            if (nums[i] + nums[j] > target)
                j--;
            else if (nums[i] + nums[j] < target)
                i++;
            else {
                result.push_back(i + 1);
                result.push_back(j + 1);
                break;
            }
        }
        return result;
    }
};
