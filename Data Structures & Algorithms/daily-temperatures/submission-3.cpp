class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        vector<int> sTemp;
        sTemp.reserve(n);
        for (int i = 0; i < n; i++) {
            while (!sTemp.empty() && temperatures[sTemp.back()] < temperatures[i]) {
                result[sTemp.back()] = i - sTemp.back();
                sTemp.pop_back();
            }
            sTemp.push_back(i);
        }

        return result;
    }
};
