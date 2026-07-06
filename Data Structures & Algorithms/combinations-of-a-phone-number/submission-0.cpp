class Solution {
   public:
    vector<string> keypad = {
        "",      // 0
        "",      // 1
        "abc",   // 2
        "def",   // 3
        "ghi",   // 4
        "jkl",   // 5
        "mno",   // 6
        "pqrs",  // 7
        "tuv",   // 8
        "wxyz"   // 9
    };
    vector<string> result;
    string t;
    void recurse(vector<string>& result, int no, string digits) {
        int n = digits.size();
        if (no >= n) {
            result.push_back(t);
            return;
        }
        int number = digits[no] - '0';
        for (int k = 0; k < keypad[number].size(); k++) {
            t += keypad[number][k];
            recurse(result, no + 1, digits);
            t.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        recurse(result, 0, digits);
        return result;
    }
};
