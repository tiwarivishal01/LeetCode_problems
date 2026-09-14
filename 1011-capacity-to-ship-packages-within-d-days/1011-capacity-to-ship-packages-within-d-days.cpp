class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int high = accumulate(weights.begin(),weights.end(),0);
        int low = *max_element(weights.begin(),weights.end());
        while(low<high){
            int mid = low + (high - low)/2;
            int cap = mid;
            int day=1;
            for(int i=0;i<weights.size();i++)
            {
                if(cap>=weights[i]){
                    cap -= weights[i];

                }else{
                    day++;
                    cap = mid - weights[i];
                }
                
            
            }
            if(day<=days){
                high = mid ;
            }else{
                low = mid + 1;
            }
        } 
        return low;
        
    }
};