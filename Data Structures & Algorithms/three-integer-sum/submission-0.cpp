class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int val1 = nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int val2 = nums[left];
                int val3 = nums[right];
                if (val1 + val2 + val3 == 0) {
                    vector<int> iVal = {val1, val2, val3};
                    if (find(result.begin(), result.end(), iVal) == result.end())
                        result.push_back(iVal);
                    left++;
                    right--;
                } else if (val1 + val2 + val3 > 0)
                    right--;
                else
                    left++;
            }
        }
        return result;
    }
};
