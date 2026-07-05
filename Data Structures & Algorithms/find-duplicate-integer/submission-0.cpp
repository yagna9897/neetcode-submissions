class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int result = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            int val = nums[abs(nums[i]) - 1];
            if(val < 0) return abs(nums[i]);
            nums[abs(nums[i]) - 1] *= -1;
        }
        return result;
    }
};
