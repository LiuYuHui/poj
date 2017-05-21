#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;
const int maxn = 25000 + 10;
struct point {
  int s, e;
};
bool cmp(const point &a, const point &b) { return a.s < b.s; }
point a[maxn];
int main() {
  int n, t;
  scanf("%d%d", &n, &t);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i].s, &a[i].e);
  }
  sort(a, a + n, cmp);
  int lastEnd = 0, ans = 0, idx = 0;
  while (lastEnd < t && idx < n) {
    int maxEnd = lastEnd;
    if (a[idx].s > lastEnd + 1)
      break;
    while (a[idx].s <= lastEnd + 1 && idx < n) {
      maxEnd = max(maxEnd, a[idx].e);
      idx++;
    }
    lastEnd = maxEnd;
    ans++;
  }
  if (lastEnd >= t)
    printf("%d\n", ans);
  else
    printf("-1\n");
}