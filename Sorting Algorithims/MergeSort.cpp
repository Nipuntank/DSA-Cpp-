#include <iostream>
using namespace std;
void Merge(int *arr, int start, int mid, int end)
{
    int a = start, b = mid, c = mid + 1, d = end, ans[d - a + 1], k = 0;
    while (a <= b && c <= d)
    {
        if (arr[a] <= arr[c])
        {
            ans[k] = arr[a];
            a++;
        }
        else
        {
            ans[k] = arr[c];
            c++;
        }
        k++;
    }
    while (a <= b)
    {
        ans[k] = arr[a];
        a++;
        k++;
    }
    while (c <= d)
    {
        ans[k] = arr[c];
        c++;
        k++;
    }
    int j = 0;
    for (int i = start; i <= d; i++)
    {
        arr[i] = ans[j];
        j++;
    }
}
void MergeSort(int *arr, int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int mid = (si + ei) / 2;
    MergeSort(arr, si, mid);
    MergeSort(arr, mid + 1, ei);
    Merge(arr, si, mid, ei);
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
    MergeSort(arr, 0, n - 1);
    cout << "After Sorting:";
    print(arr, n);

    return 0;
}