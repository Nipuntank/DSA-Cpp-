#include<iostream>
using namespace std;
int lcs(string s,string t)
{
    // base case 
    if(s.size()==0 || t.size()==0)
    {
        return 0;
    }
    //recursive call
    if(s[0]==t[0])
    {
        return 1+lcs(s.substr(1),t.substr(1));
    }
    else
    {
        int a = lcs(s.substr(1),t);
        int b = lcs(s,t.substr(1));
        return max(a,b);
    }
}
int lcs_mem(string s,string t,int **arr)
{
    int m=s.size();
    int n=t.size();
    // base case
    if(s.size()==0 || t.size()==0)
    {
        return 0;
    }
    if(arr[m][n]!=-1)
    {
        return arr[m][n];
    }
    int ans;
    if(s[0]==t[0])
    {
        ans = 1+lcs_mem(s.substr(1),t.substr(1),arr);
    }
    else
    {
        int a = lcs_mem(s.substr(1),t,arr);
        int b = lcs_mem(s,t.substr(1),arr);
        int c =lcs_mem(s.substr(1),t.substr(1),arr);
        ans = max(a,max(b,c));
    }
    arr[m][n]=ans;
    return ans;
}
int lcs_mem(string s,string t)
{
    int m=s.size();
    int n = t.size();
    int **arr=new int*[m+1];
    for(int i=0;i<=m;i++)
    {
        arr[i]=new int[n+1];
        for(int j=0;j<=n;j++)
        {
            arr[i][j]=-1;
        }
    }
    return lcs_mem(s,t,arr);
}
int lcs_dp(string s,string t)
{
    int m=s.size();
    int n = t.size();
    int **output=new int*[m+1];
    for(int i=0;i<=m;i++)
    {
        output[i]=new int[n+1];
    }
    for(int i=0;i<=n;i++)
    {
        output[0][i]=0;
    }
    for(int i=0;i<=m;i++)
    {
        output[i][0]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[m-i]==t[m-j])
            {
                output[i][j]=1+output[i-1][j-1];
            }
            else
            {
                int a = output[i-1][j];
                int b = output[i][j-1];
                int c = output[i-1][j-1];
                output[i][j]=max(a,max(b,c));
            }
        }
    }
    return output[m][n];
}
int main()
{
    string s,t;
    cin>>s>>t;
    cout<<lcs(s,t)<<endl;
    cout<<lcs_mem(s,t)<<endl;
    cout<<lcs_dp(s,t)<<endl;
    return 0;
}