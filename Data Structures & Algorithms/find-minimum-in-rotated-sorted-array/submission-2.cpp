class Solution {
public:
    int findMin(vector<int> &nums) {
        int result = nums[0];
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r)
        {
            int m = l + (r - l)/2;
            if(nums[m] > nums[r])
            {
                l = m + 1;
            }
            else 
            {
                result = std::min(nums[m],result);
                r = m - 1;
            }

        }
        return result;
    }
};
