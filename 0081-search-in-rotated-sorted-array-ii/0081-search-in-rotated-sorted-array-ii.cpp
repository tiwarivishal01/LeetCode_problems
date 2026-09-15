class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return true;
            }
            //if low and mid and high do contains duplicate
            if(nums[low]==nums[mid] && nums[mid] == nums[high]){
                high--;
                low ++;
                continue;
            }

            // if left part is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && nums[mid] > target) {
                    high = mid - 1;

                } else {
                    low = mid + 1;
                }
            }else{
                if (nums[mid] <= target && target<=nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};