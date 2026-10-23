class Solution {
public:
    int helper(int maxVal, vector<int>&profit, vector<int>&dp){
        if(maxVal<0) return 0;
        if(dp[maxVal] != -1) return dp[maxVal];
        //what if we take it 
        int takeit = profit[maxVal] + helper(maxVal-2, profit, dp);
        //skip it 
        int skipit = helper(maxVal-1, profit, dp);
        
        return dp[maxVal] = max(takeit,skipit);
    }
    int deleteAndEarn(vector<int>& nums) {
        // thinking.. 
        // what if somehow i can have the value and the max i can have i i delete them means
        // 2 2 3 3 3 4 --> (2,2),(3,3),(4,1)--> what if we have a releation in index and profit we can have so use given array
        // find the max eleemt in the array --> 4 make a profit array of size 4 now put the total profir we may have if we consider this erlemt such as index = 0 1 2 3 4
        //              0 0 4 9 4        means elememnt * occurance
        // now as in house robber check for take it and not take it

        int n = nums.size();
        if(n==1) return nums[0];
        int m = *max_element(nums.begin(),nums.end());
        vector<int>profit(m+1,0);
        for(auto acc : nums){
            profit[acc]+=acc;
        }
        vector<int>dp(m+1, -1);
        
        return helper(m, profit, dp);
    }
};