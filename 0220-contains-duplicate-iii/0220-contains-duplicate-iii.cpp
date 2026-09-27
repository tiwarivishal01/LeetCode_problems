class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<long long> st;

        for (int right = 0; right < nums.size(); right++) {

            if (right > indexDiff) {
                st.erase(st.find(nums[right - indexDiff - 1]));
            }

            auto it = st.lower_bound((long long)nums[right] - valueDiff);

            if (it != st.end() && *it <= (long long)nums[right] + valueDiff) {
                return true;
            }

            st.insert(nums[right]);
        }

        return false;
    }
};