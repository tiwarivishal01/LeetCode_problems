class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char, int> freq;
        int left = 0, right = 3;
        int cnt = 0;
        for (int i = 0; i < right; i++) {
            freq[s[i]]++;
        }

        if (freq.size() == 3)
            cnt++;
        while (right < s.size()) {

            // if window do allready have some similer element in the freq;
            freq[s[left]]--;
            if (freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;

            freq[s[right]]++;

            if (freq.size() == 3)
                cnt++;

            right++;
        }
        return cnt;
    }
};