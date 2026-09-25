class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int left =0, right =k;
        double avg=0, sum =0;
        int cnt =0;
        for(int i=0;i<k;i++){
            sum +=nums[i];
        }
        avg = sum /k;
        if(avg>=threshold) cnt++;
        while(right<nums.size()){
            sum -= nums[left];
            sum += nums[right];

            avg = sum/k;
            if(avg>=threshold){
                cnt++;
            }
            left++;
            right++;
            
        }
        return cnt;
        
    }
};