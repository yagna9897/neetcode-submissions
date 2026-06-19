class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int result = 0;
        int l = 0;
        int r = n - 1;
        while(l < r)
        {
            int temp = min(heights[l], heights[r]);
            result = max(temp * (r - l), result);
            if(heights[l] > heights[r])
                r--;
            else
                l++;
        }
        return result;
    }
};
