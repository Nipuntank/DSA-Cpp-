#include<iostream>
#include<climits>
using namespace std;
// brute Approach
int minCostPath(int **arr,int m,int n,int i,int j)
{
    // base case 
    if(i==m-1 && j==n-1)
    {
        return arr[i][j];
    }
    if(i>=m || j>=n)
    {
        return INT_MAX;
    }
    // recursive call
    int x = minCostPath(arr,m,n,i+1,j);
    int y = minCostPath(arr,m,n,i,j+1);
    int z = minCostPath(arr,m,n,i+1,j+1);
    //small calculation
    int ans = min(x,min(y,z))+arr[i][j];
    return ans;
}
int minCostPath(int **arr,int m,int n)
{
    return minCostPath(arr,m,n,0,0);
}
// Memoziation
int minCostPath_Mem(int **arr,int m,int n,int i,int j,int **output)
{
    if(i==m-1 && j==n-1)
    {
        return arr[i][j];
    }
    if(i>=m || j>=n)
    {
        return INT_MAX;
    }
    if(output[i][j]!=-1)
    {
        return output[i][j];
    }
    int x = minCostPath_Mem(arr,m,n,i+1,j,output);
    int y = minCostPath_Mem(arr,m,n,i,j+1,output);
    int z = minCostPath_Mem(arr,m,n,i+1,j+1,output);

    int value = min(x,min(y,z))+arr[i][j];
    output[i][j]=value;
    return value;
}
int minCostPath_Mem(int **arr,int m,int n)
{
    int **output=new int*[m];
    for(int i=0;i<m;i++)
    {
        output[i]=new int[n];
        for(int j=0;j<=n;j++)
        {
            output[i][j]=-1;
        }
    }
    return minCostPath_Mem(arr,m,n,0,0,output);
}
// DP
int minCostPath_dp(int **arr,int m,int n)
{
    int **output=new int*[m];
    for(int i=0;i<m;i++)
    {
        output[i]=new int[n];
    }
    output[m-1][n-1]=arr[m-1][n-1];
    // fill the last row (right to left)
    for(int i=n-2;i>=0;i--)
    {
        output[m-1][i]=output[m-1][i+1]+arr[m-1][i];
    }
    // fill the last coloumn for(bottom to top)
    for(int i=m-2;i>=0;i--)
    {
        output[i][n-1]=output[i+1][n-1]+arr[i][n-1];
    }
    // fill the remaining portion
    for(int i=m-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            output[i][j]=min(output[i][j+1],min(output[i+1][j],output[i+1][j+1]))+arr[i][j];
        }
    }
    return output[0][0];
}
int main()
{
    int m,n;
    cin>>m>>n;
    int **arr=new int*[m];
    for(int i=0;i<m;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<minCostPath(arr,m,n)<<endl;
    cout<<minCostPath_Mem(arr,m,n)<<endl;
    cout<<minCostPath_dp(arr,m,n)<<endl;

    return 0;
}