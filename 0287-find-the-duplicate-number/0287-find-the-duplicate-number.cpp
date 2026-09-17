class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int entry = 0;
        while (slow != entry) {
            slow = nums[slow];
            entry = nums[entry];
        }
        return entry;
    }
};