class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        unordered_map<int, int> mpp;
        int ans = 0;
        for (auto acc : nums) {
            mpp[acc]++;
        }
        for (auto& [x, count] : mpp) {
            if (mpp.count(x + 1)) {
                ans = max(ans, count + mpp[x + 1]);
            }
        }

        return ans;
    }
};