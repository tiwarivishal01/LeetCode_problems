class Solution {
public:
    int maxSatisfied(vector<int>& customer, vector<int>& grumpy, int minutes) {
        int left = 0, right = minutes;
        int base = 0, window =0, maxWindow = 0;
        for(int i =0;i<customer.size();i++){
         if(grumpy[i]==0){
            base += customer[i];
         }
        }
        for(int i = 0; i < minutes; i++) {
            if(grumpy[i] == 1) {
                window += customer[i];
            }
        }
        maxWindow = window;
        while(right<customer.size()){

            if(grumpy[left]==1){
                window -= customer[left];
            }

            if(grumpy[right]==1){
                window += customer[right];
            }
            left++;
            right++;

            maxWindow = max(window, maxWindow);


        }
        return maxWindow + base;

    }
};