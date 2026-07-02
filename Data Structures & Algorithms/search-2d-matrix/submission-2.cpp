class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[n-1].size();

        for(int i = 0; i < n; i++)
        {
            int l1 = matrix[i][0];
            int r1 = matrix[i][m-1];
            if(l1 <= target && r1 >= target)
            {
                if(l1 == target || r1 == target)
                    return true;
                int l = 0;
                int r = m-1;
                while(l <= r)
                {
                    int mid = l + (r-l)/2;
                    int num = matrix[i][mid];
                    if(num == target)
                        return true;
                    else if (num < target)
                        l = mid + 1;
                    else 
                        r = mid-1;
                }
            }
        }
        return false;
    }
};
