class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> freqMap;
        for(auto i : nums)
        {
            if(freqMap.find(i) == freqMap.end())
                freqMap.insert({i, 1});
            else
                freqMap[i]++;
        }

        priority_queue<pair<int, int>> pq;
        for(auto it = freqMap.begin(); it != freqMap.end(); ++it)
        {
            pq.push({it->second, it->first});
        }

        vector<int> result;
        while(k--)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
