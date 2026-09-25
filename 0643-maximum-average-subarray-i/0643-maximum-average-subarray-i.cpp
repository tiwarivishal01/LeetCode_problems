class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0, right = k;
        double sum = 0;
        double maxi = 0;
        double avg;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        maxi = sum/k;
        while(right < nums.size()){
            sum += nums[right];
            sum -= nums[left];
            left++;
            right++;
            avg = sum/k;
            maxi = max(maxi,avg);
            
        }return maxi;
        
    }
};