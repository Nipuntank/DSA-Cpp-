#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partion(int *arr, int start, int end)
{
    int pivot=arr[end];
    int i=start;
    for(int j=start;j<end;j++)
    {
        if(arr[j]<pivot)
        {
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[i],&arr[end]);
    return i;
}
void quick_sort(int *arr, int start, int end)
{
    if(start>=end)
    {
        return;
    }
    int pi = partion(arr, start, end);
    quick_sort(arr, start, pi-1);
    quick_sort(arr, pi+1, end);
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
    quick_sort(arr, 0, n-1);
    cout << "After Sorting:";
    print(arr, n);
    return 0;
}