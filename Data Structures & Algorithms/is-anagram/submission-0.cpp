class Solution {
public:
    bool isAnagram(string s, string t) {
        int ns = s.length();
        int nt = t.length();
        if(nt != ns) return false;

        vector<int> vs(26, 0);
        for(auto is : s)
        {
            int iv = is - 'a';
            vs[iv]++;
        }

        for(auto it : t)
        {
            int iv = it - 'a';
            vs[iv]--;
        }

        for(auto iv : vs)
        {
            if(iv != 0)
                return false;
        }

        return true;
    }
};
