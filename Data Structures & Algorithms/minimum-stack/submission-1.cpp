class MinStack {
   private:
    stack<int> s1;
    stack<int> minS1;

   public:
    MinStack() {}

    void push(int val) {
        s1.push(val);
        if (minS1.empty() || (!minS1.empty() && minS1.top() >= val)) 
            minS1.push(val);
    }

    void pop() {
        int t = s1.top();
        s1.pop();

        if (minS1.top() == t) minS1.pop();
    }

    int top() { return s1.top(); }

    int getMin() { return minS1.top(); }
};
