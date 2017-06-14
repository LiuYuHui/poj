#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
const int mx = 10000 + 10;
struct point {
  int x, y;
  point() {}
  point(int x, int y) : x(x), y(y) {}
  // friend bool operator<(point &a, point &b) { return a.x < b.x; }
};
bool cmp(const point &a, const point &b) { return a.x < b.x; }
point a[mx];
int n, p, l;
void solve() {
  priority_queue<int> pq;
  a[n].x = l, a[n].y = 0;
  n++;
  int ans = 0, pos = 0, capacity = p;
  for (int i = 0; i < n; i++) {
    int d = a[i].x - pos;
    while (capacity - d < 0) {
      if (pq.empty()) {
        cout << "-1" << endl;
        return;
      }
      capacity += pq.top();
      pq.pop();
      ans++;
    }
    capacity -= d;
    pos = a[i].x;
    pq.push(a[i].y);
  }
  cout << ans << endl;
}
int main() {
  // sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  cin >> l >> p;
  for (int i = 0; i < n; i++) {
    a[i].x = l - a[i].x;
  }
  sort(a, a + n, cmp);
  solve();
}