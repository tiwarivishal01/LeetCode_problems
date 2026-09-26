class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> minq;
        deque<int> maxq;
        int left =0;
        int maxi = 0;

        for (int right = 0; right < n; right++) {
            // saFE minq
            while(!minq.empty() && nums[minq.back()] > nums[right]) {
                minq.pop_back();
                
            }
            minq.push_back(right);
            // safe maxq
            while (!maxq.empty() && nums[maxq.back()] < nums[right]) {
                maxq.pop_back();
                
            }
            maxq.push_back(right);
            
            while ((nums[maxq.front()] - nums[minq.front()]) > limit) {
                if (minq.front() == left) {
                    minq.pop_front();
                }

                if (maxq.front() == left) {
                    maxq.pop_front();
                }

                left++;
            }
            maxi = max(maxi, right - left + 1);
        }
        return maxi;
    }
};