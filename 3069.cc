#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
const int mx = 1000 + 10;
int a[mx];
int r, n;
void solve() {
  int i = 0, ans = 0;
  while (i < n) {
    int x = a[i++];
    while (i < n && a[i] <= x + r)
      i++;
    int p = a[i - 1]; //在此安放哨兵
    while (i < n && a[i] <= p + r)
      i++; //寻找下个安防点
    ans++;
  }
  cout << ans << endl;
}
int main() {
  while (cin >> r >> n && r != -1) {

    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a, a + n);
    solve();
  }
}