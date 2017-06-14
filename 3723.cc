#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
const int maxn = 50000 + 10;
const int mx = 20000 + 10;
int par[mx];
int n, m, r;
int rank[mx];
struct edge {
  int u, v, cost;
  edge() {}
  edge(int u, int v, int c) : u(u), v(v), cost(c) {}
};
bool cmp(const edge &e1, const edge &e2) { return e1.cost < e2.cost; }
edge es[maxn];

int find(int x) { return (par[x] == x) ? x : par[x] = find(par[x]); }
bool same(int u, int v) { return find(u) == find(v); }
void unite(int u, int v) {
  int x = find(u), y = find(v);
  if (rank[x] < rank[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rank[x] == rank[y])
      rank[x]++;
  }
}
int kruskal() {
  int res = 0;
  for (int i = 0; i < r; i++) {
    edge e = es[i];
    if (!same(e.u, e.v)) {
      unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}

int main() {
  // freopen("out.txt", "w", stdout);
  int t;
  scanf("%d", &t);
  while (t--) {
    // cin >> n >> m >> r;
    scanf("%d%d%d", &n, &m, &r);
    int u, v, c;
    for (int i = 0; i < r; i++) {
      // cin >> u >> v >> c;
      scanf("%d%d%d", &u, &v, &c);
      es[i] = edge(u, n + v, -c);
    }
    sort(es, es + r, cmp);
    for (int i = 0; i < n + m; i++) {
      par[i] = i;
      rank[i] = 0;
    }
    // cout << (n + m) * 10000 + kruskal() << endl;
    printf("%d\n", (n + m) * 10000 + kruskal());
  }
}