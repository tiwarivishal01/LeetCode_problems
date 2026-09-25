class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int n = s.size();
        int longest = 0, maxi = 0;
        unordered_map<char, int> mpp;
        while (right < n) {
            if (!mpp.contains(s[right])) {
                mpp[s[right]]++;
            } else {
                mpp[s[right]]++;
                while (mpp[s[right]] > 1) {
                    mpp[s[left]]--;
                    left++;
                }
            }
            longest = right - left + 1;
            maxi = max(maxi, longest);

            right++;
        }
        return maxi;
    }
};