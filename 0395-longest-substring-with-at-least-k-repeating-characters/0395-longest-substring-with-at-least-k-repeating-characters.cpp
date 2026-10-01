class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxi = 0;
        for (int target = 1; target <= 26; target++) {

            int left = 0, right = 0;
            int distCnt = 0, valCnt = 0;
            vector<int> freq(26, 0);

            while (right < s.size()) {
                // Add right character
                char c = s[right];
                freq[c - 'a']++;

                // 0 -> 1
                if (freq[c - 'a'] == 1)
                    distCnt++;

                // k-1 -> k
                if (freq[c - 'a'] == k)
                    valCnt++;
                // while window becomes invalid shrink the window;
                while (distCnt > target) {

                    char c = s[left];
                    freq[c - 'a']--;

                    // 1 -> 0
                    if (freq[c - 'a'] == 0)
                        distCnt--;

                    // k -> k-1
                    if (freq[c - 'a'] == k - 1)
                        valCnt--;

                    left++;
                }
                if (distCnt == target && valCnt == target) {
                    maxi = max(maxi, right - left + 1);
                }

                right++;
            }
        }
        return maxi;
    }
};