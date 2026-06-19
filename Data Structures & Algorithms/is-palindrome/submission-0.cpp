class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0; i < s.length(); i++)
        {
            if(!isalnum(s[i])) 
            {
                s.erase(i, 1);
                i--;
            }
            else
            {
                s[i] = tolower(s[i]);
            }
        }

        int left = 0;
        int right = s.length() - 1;
        while(left < right)
        {
            if(s[left] == s[right])
            {
                left++;
                right--;
            }
            else
                return false;
        }

        return true;
    }
};
