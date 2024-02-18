#include <iostream>
using namespace std;
int n = 9;
bool isEmptyLocation(int **arr,int &row,int &col)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}
bool isHorizontal(int **arr,int row,int col,int val)
{
    for(int i=0;i<n;i++)
    {
        if(arr[row][i]==val)
        {
            return false;
        }
    }
    return true;
}
bool isVertical(int **arr,int row,int col,int val)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i][col]==val)
        {
            return false;
        }
    }
    return true;
}
bool isBox(int **arr,int row,int col,int val)
{
    int rowF=row-(row%3);
    int colF = col - (col%3);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i+rowF][j+colF]==val)
            {
                return false;
            }
        }
    }
    return false;
}
bool isSafe(int **arr,int row,int col,int val)
{
    if(isHorizontal(arr,row,col,val) && isVertical(arr,row,col,val) && isBox(arr,row,col,val))
    {
        return true;
    }
    return false;
}
bool solveSudoko(int **arr)
{
    int row = 0, col = 0;
    if (!isEmptyLocation(arr, row, col))
    {
        return true;
    }
    for (int i = 1; i <= n; i++)
    {
        if (isSafe(arr, row, col, i))
        {
            arr[row][col] = i;
            if (solveSudoko(arr))
            {
                return true;
            }
            arr[row][col] = 0;
        }
    }
    return false;
}
void SudokoSolver(int board[][9])
{
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = board[i][j];
        }
    }
    if (solveSudoko(arr))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}
int main()
{
    int board[9][9];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    SudokoSolver(board);
    return 0;
}