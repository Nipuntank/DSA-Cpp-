#include <iostream>
#include <queue>
using namespace std;

int minOperation(vector<int> arr, int start, int end, int n)
{
    if (start == end)
    {
        return 0;
    }
    int mod = 1000;
    vector<int> steps(1000, 1e9);
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    steps[start] = 0;
    while (!q.empty())
    {
        int num = q.front().first;
        int c = q.front().second;
        q.pop();
        for (auto it : arr)
        {
            int temp = (it * num) % mod;
            if (c + 1 < steps[temp])
            {
                steps[temp] = c + 1;
                if (temp == end)
                {
                    return steps[temp];
                }
                q.push(make_pair(temp, c + 1));
            }
        }
    }
    return -1;
}
int main()
{
    int n;
    cout << "Enter the size of the array :";
    cin >> n;
    int start, end;
    cout << "Enter the start and end :";
    cin >> start >> end;
    vector<int> arr(100, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = minOperation(arr, start, end, n);
    cout<<"Minimum number of multiplication operation required : ";
    cout << ans<<endl;

    return 0;
}