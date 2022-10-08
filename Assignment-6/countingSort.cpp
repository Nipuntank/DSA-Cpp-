#include <iostream>
using namespace std;
void CountSort(int *arr, int n)
{
    int k = arr[0];
    for (int i = 0; i < n; i++)
    {
        k = max(k, arr[i]);
    }
    int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    for(int i=1;i<=k;i++)
    {
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--)
    {
        output[--count[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
}
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n, arr[100];
    cout << "Enter the size of the array:";
    cin >> n;
    cout << "Enter the array:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Intial Array:";
    print(arr, n);
    CountSort(arr, n);
    cout << "After Sorting:";
    print(arr, n);
    return 0;
}