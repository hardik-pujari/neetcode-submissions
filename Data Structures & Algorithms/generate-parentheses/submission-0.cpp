class Solution {
   public:
   vector<string> result;
   string s;
    void recurse(string& s, int open, int closed, vector<string>& result, int n) {
        if (open == n && closed == n) {
            result.push_back(s);
            return;
        }
        if (open < n) {
            s += '(';
            recurse(s, open+1, closed , result, n);
            s.pop_back();
        }
        if(closed < open){
            s += ')';
            recurse(s, open, closed+1 , result, n );
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        recurse(s, 0 , 0 , result, n);
        return result;
    }
};
