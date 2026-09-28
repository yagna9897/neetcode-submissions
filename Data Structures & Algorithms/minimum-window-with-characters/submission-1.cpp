class Solution {
public:
    string minWindow(string s, string t) {
        int ns = s.length();
        int nt = t.length();
        if(nt > ns) return "";

        vector<int> ReqFreq(128, 0);
        int required = 0;
        for(auto c : t)
        {
            if(ReqFreq[c] == 0)
                required++;
            ReqFreq[c]++;
        }

        string result = "";
        vector<int> window(128, 0);
        int left = 0;
        int matched = 0;
        int Start = 0;
        int minLength = INT_MAX;
        
        for(int right = 0; right < ns; right++)
        {
            window[s[right]]++;
            if(window[s[right]] == ReqFreq[s[right]])
                matched++;
            
            while(matched == required)
            {
                int currentLength = right - left + 1;
                if(currentLength < minLength)
                {
                    minLength = currentLength;
                    Start = left;
                }
                
                window[s[left]]--;
                if(window[s[left]] < ReqFreq[s[left]])
                    matched--;
                left++;
            }
        }

        if(minLength != INT_MAX)
            result = s.substr(Start, minLength);
        return result;
    }
};
