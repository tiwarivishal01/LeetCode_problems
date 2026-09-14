class Solution {
public:
    vector<vector<int>>ans;
    vector<int>temp;
    void solve(vector<int> &candidate, int target, int index){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0 || index == candidate.size()){
            return;
        }
        temp.push_back(candidate[index]);
        solve(candidate,target-candidate[index],index);

        temp.pop_back();

        solve(candidate,target,index+1);
    }


    vector<vector<int>> combinationSum(vector<int>& candidate, int target) {
        solve(candidate,target,0);
        return ans;
        
    }
};