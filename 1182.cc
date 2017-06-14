#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
const int maxk = 100000 + 10;
const int maxn = 50000 + 10;
int rank[maxn * 3];
int parent[maxn * 3];
// struct node {
//   int t, x, y;
// };
// node a[maxk];
void init(int x) {
  for (int i = 0; i < x; i++) {
    parent[i] = i;
    rank[i] = 0;
  }
}
int find(int x) {
  if (x == parent[x])
    return x;
  else {
    return parent[x] = find(parent[x]);
  }
}
void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (rank[x] < rank[y]) {
    parent[x] = y;
  } else {
    parent[y] = x;
    if (rank[x] == rank[y]) {
      rank[x]++;
    }
  }
}
bool same(int x, int y) { return find(x) == find(y); }
// x,x+n,x+2n represents a,b,c
int n, k;
int main() {
  // ios::sync_with_stdio(false);
  // cin >> n >> k;
  scanf("%d%d", &n, &k);
  init(n * 3);
  int ans = 0;
  int t, x, y;
  for (int i = 0; i < k; i++) {
    // cin >> t >> x >> y;
    scanf("%d%d%d", &t, &x, &y);
    x -= 1, y -= 1;
    if (x < 0 || x >= n || y < 0 || y >= n) {
      ans++;
      continue;
    }
    if (t == 1) {
      if (same(x, y + n) || same(x, y + 2 * n) || same(x + n, y + 2 * n)) {
        ans++;
      } else {
        unite(x, y);
        unite(x + n, y + n);
        unite(x + 2 * n, y + 2 * n);
      }
    } else {
      if (same(x, y) || same(x, y + 2 * n)) {
        ans++;
      } else {
        unite(x, y + n);
        unite(x + n, y + 2 * n);
        unite(x + 2 * n, y);
      }
    }
  }
  // cout << ans << endl;
  printf("%d\n", ans);
}
