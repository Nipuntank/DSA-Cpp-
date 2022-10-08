#include <iostream>
using namespace std;
void insertion_sort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int current = arr[i], j;
        for (j = i - 1; j >= 0; j--)
        {
            if (current < arr[j])
            {
                arr[j + 1] = arr[j];
            }
            else
                break;
        }
        arr[j+1] = current;
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
    cout << "Enter the element in the array:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Intial Array:";
    print(arr, n);
    insertion_sort(arr, n);
    cout << "After sorting:";
    print(arr, n);
    return 0;
}