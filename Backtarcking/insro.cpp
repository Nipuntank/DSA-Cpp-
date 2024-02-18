
bool isSafe(int r, int c, int grid[N][N], int val)
{
    for (int i = 0; i < N; i++)
    {
        if (grid[r][i] == val)
            return 0;
        if (grid[i][c] == val)
            return 0;

        if (grid[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == val)
            return 0;
    }
    return 1;
}

bool SolveSudoku(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(i, j, grid, val))
                    {
                        grid[i][j] = val;
                        bool next = SolveSudoku(grid);
                        if (next)
                            return 1;
                        else
                            grid[i][j] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
    // Your code here
}

// Function to print grids of the Sudoku.
void printGrid(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << " ";
        // cout<<endl;
    }
    // Your code here
}