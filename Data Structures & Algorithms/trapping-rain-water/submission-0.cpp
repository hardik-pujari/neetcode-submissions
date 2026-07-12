class Solution {
   public:
    vector<int> prefixMax(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = max(pre[i - 1], nums[i]);
        }
        return pre;
    }
    vector<int> suffixMax(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf(n);
        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = max(suf[i + 1], nums[i]);
        }
        return suf;
    }
    int trap(vector<int>& height) {
        // just get to the next greater
        int n = height.size();
        vector<int> suf = suffixMax(height);
        vector<int> pre = prefixMax(height);
        int s = 0;
        for (int i = 0; i < n; i++) {
            int sv = suf[i];
            int pv = pre[i];
            int w = min(sv,pv) - height[i];
            s+=w;
        }
        return s;
    }
};
