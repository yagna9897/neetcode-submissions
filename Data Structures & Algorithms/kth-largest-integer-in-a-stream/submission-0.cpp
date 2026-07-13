class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int kk;
public:
    KthLargest(int k, vector<int>& nums) {
        kk = k;
        for(auto num : nums)
            pq.push(num);

        while(pq.size() > kk)
            pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > kk)
            pq.pop();
        return pq.top();
        
    }
};
