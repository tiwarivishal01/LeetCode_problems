class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        //left and rights are eliminated 
        int row = 0, col = cols -1;
        while(row<rows && col>=0){
            int current = matrix[row][col];
            if(current == target){
                return true;
            }else if(current<target){
                row++;
            }else{
                col--;
            }
        }
        return false;
        
    }
};