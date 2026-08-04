class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        vector<int> leftMax(height.size(), 0);
        leftMax[0] = height[0];
        vector<int> rightMax(height.size(), 0);
        rightMax[rightMax.size() - 1] = height[height.size() - 1];
        int res = 0;
        for (int i = 1; i < height.size(); i++)
            leftMax[i] = height[i] < leftMax[i - 1] ? leftMax[i - 1] : height[i];

        for (int i = height.size() - 2; i >= 0; i--)
            rightMax[i] = height[i] < rightMax[i + 1] ? rightMax[i + 1] : height[i];

        for (int i = 0; i < height.size() - 1; i++) {
            int temp = leftMax[i] < rightMax[i] ? leftMax[i] : rightMax[i];
            res += temp - height[i];
        }
        return res;
    }
};
