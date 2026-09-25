class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int left = 0, right = k;
        long long sum = 0, maxi = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
            sum += nums[i];
        }
        if (freq.size() == k) {
            maxi = sum;
        }
        while (right < nums.size()) {
            // elements that are leaving
            sum -= nums[left];
            freq[nums[left]]--;
            if (freq[nums[left]] == 0) {
                freq.erase(nums[left]);
            }

            // elsements that are coming in the window
            sum += nums[right];
            freq[nums[right]]++;
            if (freq.size() == k) {
                maxi = max(maxi, sum);
            }
            left++;
            right++;
        }
        return maxi;
    }
};