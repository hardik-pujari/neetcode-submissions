class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n > m)
            return findMedianSortedArrays(nums2, nums1);
        int total = n + m;
        int leftSize = (total + 1) / 2;
        int l = 0, h = n;
        while (l <= h) {
            int cut1 = l + (h - l) / 2;
            int cut2 = leftSize - cut1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (cut1 > 0) l1 = nums1[cut1 - 1];
            if (cut2 > 0) l2 = nums2[cut2 - 1];
            if (cut1 < n) r1 = nums1[cut1];
            if (cut2 < m) r2 = nums2[cut2];
            if (l1 <= r2 && l2 <= r1) {
                if (total % 2)
                    return max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2)
                h = cut1 - 1;
            else
                l = cut1 + 1;
        }
        return 0;
    }
};