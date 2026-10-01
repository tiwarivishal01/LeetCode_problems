class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int left = 0, right = 0;
        int cnt = 0;
        int n = nums.size();
        vector<int> diff(n - 1);
        // base condition
        if (nums.size() < 2) {
            return 0;
        }

        while (right < nums.size()) {
            int len = right - left + 1;
            // if windoow < 3
            if (right >= 1) {
                diff[right - 1] = (nums[right] - nums[right - 1]);
            }
            if (len >= 3) {
                if (diff[right - 2] == diff[right - 1]) {
                    int subSequenceEndingAtCurrentIndexRight = len - 2;
                    cnt += subSequenceEndingAtCurrentIndexRight;
                } else {
                    left = right - 1;
                }
            }
            right++;
        }
        return cnt;
    }
};