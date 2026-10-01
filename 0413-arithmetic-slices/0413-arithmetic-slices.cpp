class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int l = 0, r = 2, cnt = 0, len = 0;
        //base case
        if(nums.size()<3) return 0;
    
        while(r<nums.size()){
            if(nums[r]-nums[r-1]==nums[r-1]-nums[r-2]){
                len = r - l + 1;
                cnt += len - 2;
            }else{
                //reset the subsequence
                l = r -1;
            }
            r++;
        }
        return cnt;
    }
};