#include <bits/stdc++.h>
using namespace std;
long long int StaircaseHelper(long long int *ans, int n) {
  if (n <= 3) {
    if (n == 1) {
      return 1;
    }
    if (n == 2) {
      return 2;
    }
    if (n == 3) {
      return 4;
    }
  }
  if (ans[n] != -1) {
    return ans[n];
  }
  long long int a = StaircaseHelper(ans, n - 1);
  long long int b = StaircaseHelper(ans, n - 2);
  long long int c = StaircaseHelper(ans, n - 3);
  ans[n] = a + b + c;
  return ans[n];
}
long long int Staircase(int n) {
  long long int *ans = new long long int[n + 1];
  for (int i = 0; i <= n; i++) {
    ans[i] = -1;
  }
  return StaircaseHelper(ans, n);
}
int main() {

  // write your code here
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int ans = Staircase(n) % (10 ^ 9 + 7);
    cout << ans << endl;
  }
  return 0;
}