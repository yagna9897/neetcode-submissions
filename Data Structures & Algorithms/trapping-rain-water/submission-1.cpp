class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        int leftMax = height[0];
        int rightMax = height[height.size() - 1];
        int left = 1;
        int right = height.size() - 2;
        while(left <= right)
        {
            if(leftMax <= rightMax)
            {
                leftMax = leftMax > height[left] ? leftMax : height[left];
                result += leftMax - height[left];
                left++;
            }
            else
            {
                rightMax = rightMax > height[right] ? rightMax : height[right];
                result += rightMax - height[right];
                right--;
            }
        }
        return result;
    }
};
