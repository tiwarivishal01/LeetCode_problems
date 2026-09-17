class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start = 0, end = nums.size()-1;
        while(start<end){
            if(nums[start]==nums[start+1]){
                return nums[start];
            
            }
            start++;

        }
        return nums[0];
        
    }
};