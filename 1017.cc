#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;
int a[7];
int s[] = {0, 5, 3, 1};
int main() {
  while (cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] &&
         !(a[6] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0 &&
           a[5] == 0)) {
    int ans = 0;
    ans = a[6] + a[5] + a[4] + ceil(a[3] / 4.0);
    int remain_a2 = 5 * a[4] + s[a[3] % 4];
    if (a[2] > remain_a2) {
      ans += ceil((a[2] - remain_a2) / 9.0);
    }
    int remain_a1 =
        36 * ans - 36 * a[6] - 25 * a[5] - 16 * a[4] - 9 * a[3] - 4 * a[2];
    if (a[1] > remain_a1) {
      ans += ceil((a[1] - remain_a1) / 36.0);
    }
    cout << ans << endl;
  }
}