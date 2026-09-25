class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int n = nums.size();
        int longest = 0, zeroCnt = 0;
        while (right < n) {
            if (nums[right] == 0) {
                zeroCnt++;
            }

            while (zeroCnt > k) {
                if (nums[left] == 0) {
                    zeroCnt--;
                }
                left++;
            }

            longest = max(longest, (right - left + 1));
            right++;
        }
        return longest;
    }
};