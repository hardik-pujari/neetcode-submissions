class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto& it: stones){
            pq.push(it);
        }
        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x == y)
                pq.push(0);
            else 
                pq.push(abs(x-y));
        }
        return pq.top();
    }
};
