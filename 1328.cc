#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int inf = 1e9;
const int maxn = 1000 + 10;
struct point {
  double s, e;
};
point a[maxn];
int n, d, ans;
bool cmp(const point &a, const point &b) { return a.e < b.e; }
bool used[maxn];
void solve() {
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      used[i] = true;
      for (int j = i + 1; j < n; j++) {
        if (!used[j] && a[j].s <= a[i].e) {
          used[j] = true;
        }
      }
      ++ans;
    }
  }
}
int main() {
  int t = 0;
  while (~scanf("%d%d", &n, &d) && n != 0 && d != 0) {
    int maxy = -inf;
    t++;
    ans = 0;
    memset(used, false, sizeof(used));
    int x, y;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &x, &y);
      maxy = max(maxy, y);
      double len = sqrt(1.0 * d * d - y * y);
      a[i].s = x - len;
      a[i].e = x + len;
    }
    getchar();
    if (maxy > d) {
      cout << "-1" << endl;
    } else {
      sort(a, a + n, cmp);
      solve();
      printf("Case %d: %d\n", t, ans);
    }
  }
}