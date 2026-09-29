class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> req;
        vector<int> ans;
        for (auto word : words) {
            req[word]++;
        }
        int wordLen = words[0].size(), n = words.size(),
            total_len = n * wordLen;
        for (int offset = 0; offset < wordLen; offset++) {
            int cnt = 0;
            int left = offset, right = offset;
            unordered_map<string, int> window;
            while (right + wordLen <= s.size()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                // what if req dont conain the word string
                if (!req.count(word)) {
                    window.clear();
                    cnt = 0;
                    left = right;
                    continue;
                }
                // if word valid then add element into the window
                window[word]++;
                cnt++;
                // what if window have more appearance of word
                while (window[word] > req[word]) {
                    string wordToRemove = s.substr(left, wordLen);
                    window[wordToRemove]--;
                    left += wordLen;
                    cnt--;
                }
                // condition when answer will be valid
                if (cnt == n) {
                    ans.push_back(left);
                    string wordToRemove = s.substr(left, wordLen);
                    window[wordToRemove]--;
                    left += wordLen;
                    cnt--;
                }
            }
        }
        return ans;
    }
};