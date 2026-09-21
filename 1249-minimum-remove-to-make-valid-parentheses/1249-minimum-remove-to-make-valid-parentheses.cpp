class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (!st.empty() && s[i] == ')') {
                st.pop();
            } else if (st.empty() && s[i] == ')') {
                s[i] = '#';
            } else {
                continue;
            }
        }
        while (!st.empty()) {
            s[st.top()] = '#';
            st.pop();
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != '#') {
                ans += s[i];
            } else {
                continue;
            }
        }

        return ans;
    }
};