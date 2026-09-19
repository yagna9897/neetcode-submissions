class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> sTemp;
        for (int i = 0; i < n; i++) {
            while (!sTemp.empty() && temperatures[sTemp.top()] < temperatures[i]) {
                result[sTemp.top()] = i - sTemp.top();
                sTemp.pop();
            }
            sTemp.push(i);
        }

        return result;
    }
};
