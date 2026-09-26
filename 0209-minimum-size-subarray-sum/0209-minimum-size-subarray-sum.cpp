class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left =0, right =0;
        int sum = 0, minLengh = INT_MAX;
        for(int right=0;right<n;right++){
            sum += nums[right];
            //if my window is valid then only shrink the window
            while(sum>=target){
                int lengh = right-left+1;
                minLengh = min(minLengh, lengh);
                //reduce element getting outof the window
                sum -= nums[left];
                left++;
            }
        }
        return minLengh == INT_MAX ? 0 : minLengh;;
        
    }
};