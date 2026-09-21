class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> st;
        stringstream ss(path);
        string comp;
        while (getline(ss, comp, '/')) {
            if (comp.empty() || comp == ".") {
                continue;
            }

            else if (comp == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            }

            else {
                st.push(comp);
            }
        }
        vector<string> vec;
        string ans = "";
        while (!st.empty()) {
            vec.push_back(st.top());
            st.pop();
        }

        reverse(vec.begin(), vec.end());

        for (string dir : vec) {
            ans += "/" + dir;
        }
        if (ans.empty()) {
            return "/";
        }
        return ans;
    }
};