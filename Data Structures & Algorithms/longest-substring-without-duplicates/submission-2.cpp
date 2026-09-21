class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex;
        int left = 0;
        int longest = 0;

        for (int right = 0; right < s.size(); right++) {
            char ch = s[right];

            if (lastIndex.count(ch) && lastIndex[ch] >= left) {
                left = lastIndex[ch] + 1;
            }

            lastIndex[ch] = right;
            longest = max(longest, right - left + 1);
        }

        return longest;
    }
};