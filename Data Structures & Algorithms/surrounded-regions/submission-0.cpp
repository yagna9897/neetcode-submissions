class Solution {
public:
    void DFS(vector<vector<char>>& board, int row, int col)
    {
        int rows = board.size();
        int cols = board[0].size();
        if(row < 0 || row > rows - 1 || col < 0 || col > cols - 1)
            return ;
        if(board[row][col] != 'O') return;

        board[row][col] = 'T';
        if(row > 0)
            DFS(board, row - 1, col);
        if(row < rows - 1)
            DFS(board, row + 1, col);
        if(col > 0)
            DFS(board, row, col - 1);
        if(col < cols - 1)
            DFS(board, row, col + 1);
        
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if(rows < 1) return;
        int cols = board[0].size();
        if(cols < 1) return;

        // first row
        int iRow = 0;
        int iCol = 0;
        for(; iCol <= cols - 1; iCol++)
            DFS(board, iRow, iCol);

        // last col
        iRow++;
        iCol--;
        for(; iRow <= rows - 1; iRow++)
            DFS(board, iRow, iCol);

        // last row
        iCol--;
        iRow--;
        for(; iCol >= 0; iCol--)
           DFS(board, iRow, iCol);

        // first col        
        iRow--;
        iCol++;
        for(; iRow >= 1; iRow--)
          DFS(board, iRow, iCol);

        iRow = 0; 
        for(int ; iRow <= rows - 1; iRow++)
        {
            iCol = 0;
            for(; iCol <= cols - 1; iCol++)
            {
                int temp = board[iRow][iCol];
                if( temp == 'O')
                    temp = 'X';
                else if(temp == 'T')
                    temp = 'O';
                board[iRow][iCol] = temp;            }
        }
    }
};
