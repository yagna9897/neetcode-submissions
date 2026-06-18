class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        map<vector<int>, vector<string>> mAnagram;
        for(auto s : strs)
        {
            vector<int> vFreq(26, 0);
            for(auto c : s)
                vFreq[c - 'a']++;
            if(mAnagram.find(vFreq) != mAnagram.end())
                mAnagram[vFreq].push_back(s);
            else
            {
                vector<string> temp;
                temp.push_back(s);
                mAnagram.insert({vFreq, temp});
            }
        }
        vector<vector<string>> result;
        for(auto it = mAnagram.begin(); it != mAnagram.end(); ++it)
        {
            result.push_back(it->second);
        }
        return result;
    }
};
