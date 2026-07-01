class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        vector<int> numbers(n, 0);
        for (auto c : tokens) {
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                int b = numbers.back();
                numbers.pop_back();
                int a = numbers.back();
                numbers.pop_back();
                int res = 0;
                if (c == "+") {
                    res = a + b;
                } else if (c == "-") {
                    res = a - b;
                } else if (c == "*") {
                    res = a * b;
                } else if (c == "/") {
                    res = a / b;
                }
                numbers.push_back(res);
            } else {
                int num = std::stoi(c);
                numbers.push_back(num);
            }
        }
        return numbers.back();
    }
};
