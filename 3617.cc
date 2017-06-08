#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;
const int maxn = 2000 + 10;
int n;
char a[maxn];
// ofstream out("out.txt");
void solve() {
  int lo = 0, hi = n - 1;
  int num = 0;
  while (lo <= hi) {
    bool left = false;
    for (int i = 0; lo + i <= hi; i++) {
      if (a[lo + i] < a[hi - i]) {
        left = true;
        break;
      } else if (a[hi - i] < a[lo + i]) {
        left = false;
        break;
      }
    }
    ++num;
    cout << (left ? a[lo++] : a[hi--]);
    if (num % 80 == 0)
      cout << endl;
  }
}
int main() {
  // freopen("out.txt", "w", stdout);
  cin >> n;
  {
    for (int i = 0; i < n; i++)
      cin >> a[i];
    solve();
  }
}