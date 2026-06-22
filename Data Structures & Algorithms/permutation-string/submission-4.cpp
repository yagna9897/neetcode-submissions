class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if (n1 > n2) return false;

        vector<int> freq1(26,0);
        for (auto c : s1) freq1[c-'a']++;

        for (int i = 0; i <= n2 - n1; i++) {
            vector<int> freq2(26,0);
            for (int j = i; j < i + n1; j++) freq2[s2[j]-'a']++;
            if (freq1 == freq2) return true;
        }
        return false;
    }
};
