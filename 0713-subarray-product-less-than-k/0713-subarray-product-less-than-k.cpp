class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)
            return 0;

        long long mult = 1;
        int left = 0;
        int cnt = 0;

        for (int right = 0; right < nums.size(); right++) {

            mult *= nums[right];

            while (mult >= k) {
                mult /= nums[left];
                left++;
            }

            cnt += right - left + 1;
        }

        return cnt;
    }
};