class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int length = s.length();
        unordered_map<char, int> IdxMap;
        int result = 0;
        int start = 0;
        for (int i = 0; i < length; i++) {
            char c = s[i];
            if (IdxMap.find(c) != IdxMap.end()) 
                start = max(IdxMap[c] + 1, start);

            result = max(i - start + 1, result);
            IdxMap[c] = i;
        }
        return result;
    }
};
