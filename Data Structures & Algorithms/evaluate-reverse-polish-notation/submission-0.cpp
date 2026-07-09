class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                st.push(stoi(tokens[i]));
            } else {
                string oprtr = tokens[i];
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int c;
                if (oprtr == "+")
                    c = a + b;
                else if (oprtr == "*")
                    c = a * b;
                else if (oprtr == "-")
                    c = a - b;
                else 
                    c = a /b;
                st.push(c);
            }
        }
        return st.top();
    }
};
