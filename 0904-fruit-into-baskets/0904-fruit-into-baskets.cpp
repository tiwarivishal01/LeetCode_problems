class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0, right = 0;
        int maxOverall = 0;
        unordered_map<int, int> mpp;
        while (right < n) {
             mpp[fruits[right]]++;
            if (mpp.size() > 2){
                // make the window valid
                while (mpp.size() > 2) {
                    mpp[fruits[left]]--;
                    if (mpp[fruits[left]] == 0) {
                        mpp.erase(fruits[left]);
                    }
                    left++;
                }
            }
            maxOverall = max(maxOverall, right - left + 1);
            right++;
        }
        return maxOverall;
    }
};