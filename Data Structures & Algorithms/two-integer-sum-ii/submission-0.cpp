class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n1 = 0;
        int n2 = numbers.size() - 1;
        while(n1 < n2)
        {
            int temp = numbers[n1] + numbers[n2] - target;
            if(temp == 0)
                break;
            else if (temp > 0)
                n2--;
            else 
                n1++;
        }

        return {n1 + 1, n2 + 1};
    }
};
