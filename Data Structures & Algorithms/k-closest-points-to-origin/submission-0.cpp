class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>,
                       greater<pair<double, pair<int, int>>>>
            pq;
        for (auto& it : points) {
            int x = it[0];
            int y = it[1];
            double d = sqrt(pow(x, 2) + pow(y, 2));
            pq.push({d, {x, y}});
        }
        while( k > 0 && !pq.empty()){
            auto point = pq.top();
            int d = point.first;
            int x = point.second.first;
            int y = point.second.second;
            pq.pop();
            ans.push_back({x,y});
            k --;
        }
        return ans;
    }
};
