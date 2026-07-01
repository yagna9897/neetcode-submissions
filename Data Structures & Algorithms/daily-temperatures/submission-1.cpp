class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> resultStack;
        vector<int> result(n, 0);
        resultStack.push(0);
        for (int i = 1; i < n; i++) {
            while (!resultStack.empty() && temperatures[resultStack.top()] < temperatures[i]) {
                int t = resultStack.top();
                resultStack.pop();
                result[t] = i - t;
            }
            resultStack.push(i);
        }

        return result;
    }
};
