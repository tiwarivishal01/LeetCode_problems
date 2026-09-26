class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        deque<int>dq;
        for(int right=0;right<n;right++){
            //remove all smaller element starting from back
            while(!dq.empty() && nums[dq.back()]<=nums[right]){
                dq.pop_back();
            }
            //psuh the right element
            dq.push_back(right);
            int left = right - k +1;
            //if elenet is greater then front then pop front and push
            if(dq.front()<left){
                dq.pop_front();
            }
            //check the window and identify the correct ans
            if(right>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }return ans;
        
    }
};