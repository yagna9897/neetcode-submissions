class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers;
        for(int i = 0; i < nums.size(); i++)
            numbers.insert(nums[i]);

        int length = 0;
        int i = 0;
        while(i < nums.size())
        {
            if(numbers.find(nums[i]-1) != numbers.end())
            {
                i++;
                continue;
            }
            int templength = 1;
            int nb = nums[i];
            while(numbers.find(nb+1) != numbers.end())
            {
                templength++;
                nb++;
            }
            length = std::max(length, templength);
            i++;
        }
        return length;
    }
};
