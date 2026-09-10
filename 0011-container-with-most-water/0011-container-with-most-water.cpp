class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int start = 0, end = n-1;
        int maxi = INT_MIN;
        int maxWater = INT_MIN;
        while(start<end){
            maxWater = (end - start) * min(height[start],height[end]);
            maxi = max(maxi,maxWater);
            if(height[start]<height[end]){
                start++;
            }else{
                end--;
            }


        }
        return maxi;
    }
};