class Solution {
public:
    
    int helper(vector<int>& nums,vector<int>& dp){
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i=2;i<nums.size();i++){
            dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
       }
       return dp[nums.size()-1];
        
    }
    int rob(vector<int>& nums) {
        // so i have base cases now for filling my table i need to calculate all rest
        // basicalyy dp [i] = max(what if if i takeit , and what if i dont take it)
        // make sure about intialization
        vector<int>dp(nums.size(), -1);
        return helper(nums,dp);

    }
};