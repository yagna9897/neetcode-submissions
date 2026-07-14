class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto num : stones)
            pq.push(num);
        
        while(pq.size() > 1)
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            int balance = abs(x-y);
            if(balance > 0)
                pq.push(balance);
        }

        return pq.empty() ? 0 : pq.top();
    }
};
