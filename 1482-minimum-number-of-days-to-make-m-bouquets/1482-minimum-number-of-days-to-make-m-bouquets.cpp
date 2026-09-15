class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if (n < (long long)m * k) {
            return -1;
        }
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cons = 0, boq = 0;
            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= mid) {
                    cons++;
                    if (cons == k) {
                        boq++;
                        cons = 0;
                    }
                } else {
                    cons = 0;
                }
            }
            if (boq >= m) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};