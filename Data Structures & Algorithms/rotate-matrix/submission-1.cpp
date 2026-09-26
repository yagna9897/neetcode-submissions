class Solution {
    void ReverseVector(vector<int>& vec)
    {
        int n = vec.size();
        for(int i = 0; i <= (n-1)/2; i++ )
        {
            std::swap(vec[i], vec[n-i-1]);
            /*int temp = vec[n-i-1];
            vec[n-i-1] = vec[i];
            vec[i] = temp;*/
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i ; j++)
            {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < n; i++)
        {
            ReverseVector(matrix[i]);
        }
    }
};
