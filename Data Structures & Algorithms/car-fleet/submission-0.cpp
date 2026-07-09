class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        sort(cars.begin(), cars.end());
        stack<double> st;
        for (int i = n - 1; i >= 0; i--) {
            double currTime = cars[i].second;
            if (st.empty() || currTime > st.top()) {
                st.push(currTime);
            }
            // else: joins the fleet ahead, so don't push
        }
        return st.size();
    }
};