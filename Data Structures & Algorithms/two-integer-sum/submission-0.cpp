class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> targetIdxMap;
        vector<int> res;
        for(int in = 0; in < nums.size(); in++)
        {
            int temp = target - nums[in];
            if(targetIdxMap.find(temp) != targetIdxMap.end())
            {
                res.push_back(targetIdxMap[temp]);
                res.push_back(in);
                break;
            }
            else
            {
                targetIdxMap.insert({nums[in], in});
            }
        }
        return res;
    }
};
