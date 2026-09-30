class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int left = 0;
        unordered_set<string> seen;
        unordered_set<string> rep;
        for (int right = 0; right < s.size(); right++) {
            if (right - left + 1 == 10) {
                string window = s.substr(left, 10);
                // if window exist in the seen that means repeated
                if (seen.count(window)) {
                    rep.insert(window);
                } else {
                    seen.insert(window);
                }
                left++;
            }
        }
        return vector<string>(rep.begin(), rep.end());
    }
};