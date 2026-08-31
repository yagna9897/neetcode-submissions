class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> vSPos(26, 0);
        vector<int> result;

        for(int i = 0; i < s.length(); i++)
        {
            vSPos[s[i]-'a'] = i;
        }

        int idx = 0;
        while(idx < s.length())
        {
            int endPos = vSPos[s[idx] - 'a'];
            int idx2 = idx;
            while(idx2 < endPos)
            {
                int endPos2 = vSPos[s[idx2] - 'a'];
                endPos = std::max(endPos, endPos2);
                idx2++;
            }
            result.push_back(endPos - idx + 1);
            idx = endPos+1;
        }

        return result;
    }
};
