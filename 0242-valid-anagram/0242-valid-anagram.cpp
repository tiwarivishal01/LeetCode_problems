class Solution {
public:
    bool isAnagram(string s, string t) {
        // base cases if t is a anagram means s.size()>t.size()
        if (s.size() != t.size()) {
            return false;
        }
        int left = 0, right = 0;
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        // check the initial window
        for (int right = 0; right < t.size(); right++) {
            need[t[right]]++;
        }
        while (right < s.size()) {
            window[s[right]]++;
            if (right - left + 1 == t.size()) {
                if (window == need) {
                    return true;
                }
                window[s[left]]--;
                if(window[s[left]]==0){
                    window.erase(s[left]);
                }
                left++;
            }

            right++;
        }
        return false;
    }
};