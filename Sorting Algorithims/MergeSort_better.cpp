#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void SelectionSort_better(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        int max = arr[i], min = arr[i];
        int max_i = i, min_i = i;
        for (int k = i; k <=j; k++)
        {
            if (arr[k] > max)
            {
                max = arr[k];
                max_i = k;
            }
            else
            {
                if (arr[k] < min)
                {
                    min = arr[k];
                    min_i = k;
                }
            }
        }
        swap(&arr[i], &arr[min_i]);
        if (arr[min_i] == max)
        {
            swap(&arr[j], &arr[min_i]);
        }
        else
            swap(&arr[j], &arr[max_i]);
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
    SelectionSort_better(arr, n);
    cout << "After Sorting:";
    print(arr, n);
    return 0;
}