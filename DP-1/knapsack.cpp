#include<iostream>
using namespace std;
// brute force approach
//  time complexity of this approach is O(2^n);
int knapsack(int *weights,int *value,int n,int maxWeight)
{
    // base case 
    if(maxWeight==0||n==0)
    {
        return 0;
    }
    // recursive call
    if(weights[0]>maxWeight)
    {
        return knapsack(weights+1,value+1,n-1,maxWeight);
    }
    else
    {
        int a = value[0]+knapsack(weights+1,value+1,n-1,maxWeight-weights[0]);
        int b = knapsack(weights+1,value+1,n-1,maxWeight);
        return max(a,b);
    }
}
// solution using Memoization
int knapsack_mem(int *weights,int *value,int n,int maxWeight,int **output)
{
    if(n==0 || maxWeight==0)
    {
        return 0;
    }
    if(output[maxWeight][n]!=-1)
    {
        return output[maxWeight][n];
    }
    int ans;
    if(weights[0]>maxWeight)
    {
        ans = knapsack_mem(weights+1,value+1,n-1,maxWeight,output);
    }
    else
    {
        int a = value[0]+knapsack_mem(weights+1,value+1,n-1,maxWeight-weights[0],output);
        int b = knapsack_mem(weights+1,value+1,n-1,maxWeight,output);
        ans = max(a,b);
    }
    output[maxWeight][n]=ans;
    return ans;
}
int knapsack_mem(int *weights,int *value,int n,int maxWeight)
{
    int **output=new int*[maxWeight+1];
    for(int i=0;i<=maxWeight;i++)
    {
        output[i]=new int[n+1];
        for(int j=0;j<=n;j++)
        {
            output[i][j]=-1;
        }
    }
    return knapsack_mem(weights,value,n,maxWeight,output);

}
int main()
{
    int n;
    cin>>n;
    int *weights = new int[n];
    int *value = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>weights[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }
    int maxWeight;
    cin>>maxWeight;
    cout<<knapsack(weights,value,n,maxWeight)<<endl;
    cout<<knapsack_mem(weights,value,n,maxWeight)<<endl;
    return 0;
}