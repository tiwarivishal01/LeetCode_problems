class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // keeping track of last longst window
        int longest = 0;
        unordered_set<char> st;
        int left = 0, right = 0;
        while (right < s.size()) {

            // while window is inavalid
            while (st.contains(s[right])) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            int len = right - left + 1;
            longest = max(longest, len);
            right++;
        }
        return longest;
    }
};