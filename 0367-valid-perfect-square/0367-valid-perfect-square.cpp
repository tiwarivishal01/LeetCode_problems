class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 0, high = num;
        while(low<=high){
            int mid = low + (high -low)/2;
            long long mul = 1ll*mid * mid ;
            if(mul==num){
                return true;
            }else if(mul<num){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return false;
        
    }
};