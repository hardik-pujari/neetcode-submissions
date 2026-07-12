class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int i = 0 , j = n-1, area , max_area= INT_MIN;
        while(i < j){
            area = min(nums[i], nums[j]) * (j-i);
            max_area = max(max_area, area);
            if(nums[i] <= nums[j])
                i++;
            else 
                j--;
        }
        return max_area;
    }
};
