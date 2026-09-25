class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        if(s2.size() < n){
            return false;
        }
        int left =0, right = n;
        unordered_map<char,int>mpp;
        unordered_map<char,int>need;
        for(int i=0;i<n;i++){
            mpp[s1[i]]++;
        }
        //checking for the intial base window
        for(int i=0;i<n;i++){
           need[s2[i]]++;
        }
        if(need == mpp){
            return true;
        }
        

        // checking for the whole array for corresponding windows
        while(right<s2.size()){
           //remove the left char from window
           need[s2[left]]--;
           //now consider if our need dont have any apearance for that eleemnt but we still have <a:0>
           if(need[s2[left]]==0){
            need.erase(s2[left]);
           }
           // adding the right char to the window
           need[s2[right]]++;
           //checking the window if they fulfill each other
           if(need == mpp){
            return true;
           }
           left++;
           right++;

        }
        return false;
        
    }
};