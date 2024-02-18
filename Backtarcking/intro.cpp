class Solution
{
    int board[11][11];
    vector<vector<int>> soln;

public:
    bool isPossible(int n, int row, int col)
    {
        for (int i = row - 1; i >= 0; i--)
        {
            if (board[i][col] == 1)
            {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 1)
            {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 1)
            {
                return false;
            }
        }
        return true;
    }
    void nQueenHelper(int n, int row)
    {
        vector<int> ans;
        if (row == n)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    ans.push_back(board[i][j]);
                }
                soln.push_back(ans);
            }
            return;
        }
        for (int j = 0; j < n; j++)
        {
            if (isPossible(n, row, j))
            {
                board[row][j] = 1;
                nQueenHelper(n, row);
                board[row][j] = 0;
            }
        }
        return;
    }
    vector<vector<int>> nQueen(int n)
    {
        // code here
        vector<vector<int>> soln;
        memset(board, 0, 11 * 11 * sizeof(int));
        nQuuenHelper(&sol, n, 0);
        return soln;
    }
};