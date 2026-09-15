class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        if(n<=0){
            return -1;
        }
        sort(position.begin(),position.end());
        int low = 1, high = position[n-1]- position[0];
        while(low<=high){
            int mid = low + (high - low)/2;
            int cnt = 1;
            int last = position[0];
            for(int i=0;i<n;i++){
                if(position[i]-last>=mid){
                    cnt++;
                    last = position[i];
                }
            }
            if(cnt>=m){
                low = mid + 1;
            }else{
                high = mid -1;
            }
        }
        return low-1;
        
    }
};