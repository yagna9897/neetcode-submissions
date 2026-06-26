class Solution {
   public:
    bool isValid(string s) {
        stack<char> stackChar;
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[')
                stackChar.push(c);
            else if (c == ')' || c == '}' || c == ']') {
                if(stackChar.empty())
                    return false;
                else if (c == ')' && stackChar.top() == '(') {
                    stackChar.pop();
                } else if (c == '}' && stackChar.top() == '{') {
                    stackChar.pop();
                } else if (c == ']' && stackChar.top() == '[') {
                    stackChar.pop();
                } else
                    return false;
            }
        }

        if (stackChar.empty())
            return true;
        else
            return false;
    }
};
