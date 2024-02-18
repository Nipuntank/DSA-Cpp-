#include<iostream>
using namespace std;
int ans[20][20];
void printSol(int ans[][20],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<ans[i][j]<<" "; 
        }
    }
    cout<<endl;
    return ;
}
void RatMazeHelper(int Maze[][20],int n,int row,int col)
{
    if(row==n-1 && col==n-1)
    {
        ans[row][col]=1;
        printSol(ans,n);
        return ;
    }
    if(row>=n || row<=0 || col>=n || col<=0 || Maze[row][col]==0 || ans[row][col]==1)
    {
        return ;
    }
    ans[row][col]=1;
    RatMazeHelper(ans,n,row-1,col);
    RatMazeHelper(ans,n,row+1,col);
    RatMazeHelper(ans,n,row,col-1);
    RatMazeHelper(ans,n,row,col+1);
    ans[row][col]=0;
}
void RatMaze(int Maze[][20],int n)
{
    memset(ans,0,20*20*sizeof(int));
    RatMazeHelper(Maze,n,0,0);
}
int main()
{
    int n;
    cin>>n;
    int Maze[20][20]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>Maze[i][j];
        }
    }
    RatMaze(Maze,n);
    return 0;
}