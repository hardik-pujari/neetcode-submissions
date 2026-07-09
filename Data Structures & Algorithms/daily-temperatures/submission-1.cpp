class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;  // store indexes
        int n = temperatures.size();
        vector<int> ans(n);
        st.push(n - 1);
        ans[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            int val = temperatures[i];
            while (!st.empty() && val >= temperatures[st.top()]) {
                st.pop();
            }
            ans[i] = st.empty() ? 0 : (st.top() - i);
            st.push(i);
        }
        return ans;
    }
};
