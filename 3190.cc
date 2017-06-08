#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 5e4 + 10;
struct point {
  int s, e, idx;
  friend bool operator<(const point &a, const point &b) { return a.e > b.e; }
};
bool cmp(const point &a, const point &b) { return a.s < b.s; }
point a[maxn];
int n;
int ans[maxn];
int main() {
  while (~scanf("%d", &n)) {
    priority_queue<point> pq;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &a[i].s, &a[i].e);
      a[i].idx = i;
    }
    sort(a, a + n, cmp);
    pq.push(a[0]);
    int cnt = 1;
    ans[a[0].idx] = cnt;
    for (int i = 1; i < n; i++) {
      if (!pq.empty() && pq.top().e < a[i].s) {
        point tmp = pq.top();
        pq.pop();
        ans[a[i].idx] = ans[tmp.idx];
      } else {
        ans[a[i].idx] = ++cnt;
      }
      pq.push(a[i]);
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++) {
      printf("%d\n", ans[i]);
    }
  }
}