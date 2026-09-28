class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int cnt1 = 0, cnt0 = 0, ans = 0;
        int left = 0, right = 0;
        while (right < n) {
            if (s[right] == '1') {
                cnt1++;
            } else {
                cnt0++;
            }

            while (cnt1 > k && cnt0 > k) {
                if (s[left] == '1') {
                    cnt1--;
                } else {
                    cnt0--;
                }
                left++;
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
};