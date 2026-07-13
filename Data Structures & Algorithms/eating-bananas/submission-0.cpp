class Solution {
   public:
    int check(int m, vector<int>& piles, int h) {
        int n = piles.size(), s = 0;
        for (int i = 0; i < n; i++) {
            s += ceil((double)piles[i] / m);
        }
        if (s <= h) return 1;
        return 0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int min_piles = 1;
        int max_piles = *max_element(piles.begin(), piles.end());
        int n = piles.size(), ans;
        while (min_piles <= max_piles) {
            int m = (min_piles + max_piles) / 2;
            if (check(m, piles, h))  // 1
            {
                ans = m;
                max_piles = m - 1;
            } else
                min_piles = m + 1;
        }
        return ans;
    }
};
