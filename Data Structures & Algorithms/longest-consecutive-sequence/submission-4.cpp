class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        if(nums.size() < 2)
            return nums.size();
        int length = 1;
        int tempLength = 1;

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i-1])
                continue;
            else if(nums[i] == nums[i-1]+1)
                tempLength++;
            else
            {
                length = std::max(tempLength, length);
                tempLength = 1;
            }
        }
        length = std::max(tempLength,length);
        return length;
    }
};
