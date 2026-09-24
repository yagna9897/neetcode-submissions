class Solution {
    int Solve(int i, int j, const string& text1,
          const string& text2, std::vector<std::vector<int>>& dp)
    {
        if(i >= text1.length() || j >= text2.length())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int result = 0;
        if(text1[i] == text2[j])
        {
            result = 1 + Solve(i + 1, j + 1, text1, text2, dp);
        }
        else
        {
            int r1 = Solve(i + 1, j , text1, text2, dp);
            int r2 = Solve(i, j + 1, text1, text2, dp);
            result = std::max(r1, r2);
        }
        dp[i][j] = result;
        return result;
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        std::vector<std::vector<int>> dp(text1.length(), std::vector<int> (text2.length(), -1));
        return Solve(0, 0, text1, text2, dp);
    }
};
