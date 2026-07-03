class Solution {
public:
    void subset(vector<int>& nums , int curr, vector<vector<int>>& result, vector<int>& sub){
       result.push_back(sub);

       for(int i = curr ; i < nums.size(); i++){
        sub.push_back(nums[i]);
        subset(nums, i+1, result, sub);
        sub.pop_back();
       }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> result;
        subset(nums, 0 , result , sub );
        return result;
    }
};
