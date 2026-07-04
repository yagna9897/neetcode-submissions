class Solution {
public:
    int findMin(vector<int> &nums) {
        int m = nums[0];
        for(auto n : nums)
        {
            if(m > n) m = n;
        }
        return m;
    }
};
