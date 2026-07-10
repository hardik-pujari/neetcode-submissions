class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string s1;
        for (char c : s) {
            if (isalnum(c))
                s1 += c;
        }
        int i = 0, k = s1.size() - 1;
        while (i < k) {
            if (s1[i] != s1[k])
                return false;
            i++;
            k--;
        }

        return true;
    }
};