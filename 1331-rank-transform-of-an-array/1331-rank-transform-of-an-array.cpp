
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;

        sort(sortedArr.begin(), sortedArr.end());

        sortedArr.erase(
            unique(sortedArr.begin(), sortedArr.end()),
            sortedArr.end()
        );

        unordered_map<int, int> mp;

        for (int i = 0; i < sortedArr.size(); i++) {
            mp[sortedArr[i]] = i + 1;
        }

        vector<int> ans;

        for (int x : arr) {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};
