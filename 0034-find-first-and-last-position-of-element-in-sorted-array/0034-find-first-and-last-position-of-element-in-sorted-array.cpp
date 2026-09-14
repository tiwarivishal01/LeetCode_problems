class Solution {
public:
    //    int firstOcc(vector<int> &nums, int target){
    //        int n = nums.size();
    //         int low = 0, high = n-1;
    //         int ans=-1;
    //         while(low <= high){
    //             int mid = low + (high - low)/2;
    //             if(nums[mid]== target){
    //                 ans = mid;
    //                 high=mid-1;
    //             }else if(nums[mid]<target){
    //                 low = mid +1;
    //             }else{
    //                 high = mid -1;
    //             }
    //         }
    //         return ans;
    //     }
    //     int lastOcc(vector<int> &nums, int target){
    //        int n = nums.size();
    //         int low = 0, high = n-1;
    //         int ans=-1;
    //         while(low <= high){
    //             int mid = low + (high - low)/2;
    //             if(nums[mid]== target){
    //                 ans = mid;
    //                 low=mid+1;
    //             }else if(nums[mid]<target){
    //                 low = mid +1;
    //             }else{
    //                 high = mid -1;
    //             }
    //         }
    //         return ans;
    //     }

    vector<int> searchRange(vector<int>& nums, int target) {
        int fo = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (fo == nums.size() || nums[fo] != target) {
            return {-1, -1};
        }
        int lo =
            upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        vector<int> ans;
        ans.push_back(fo);
        ans.push_back(lo);
        return ans;
    }
};