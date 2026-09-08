class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProd = 1;
        for(auto num : nums)
            totalProd *= num;
        
        vector<int> result;
        for(int i = 0; i < nums.size(); i++)
        {
            int current = nums[i];
            if(current != 0)
                result.push_back(totalProd/current);
            else
            {
                int temp = 1;
                for(int j = 0; j < nums.size(); j++)
                {
                    if(j != i)
                        temp *= nums[j];
                }
                result.push_back(temp);
            }
        }

        return result;
    }
};
