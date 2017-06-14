#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 100000 + 10;
const int inf = (1 << 20);
struct edge {
  int to, cost;
  edge(int t, int c) : to(t), cost(c) {}
};
vector<edge> a[maxn];
int dis[maxn], dis2[maxn];
int n, r;
typedef pair<int, int> P;
int main() {
  int s, e, c;
  cin >> n >> r;
  for (int i = 0; i < r; i++) {
    cin >> s >> e >> c;
    s--, e--;
    a[s].push_back(edge(e, c));
    a[e].push_back(edge(s, c));
  }
  priority_queue<P, vector<P>, greater<P>> pq;
  fill(dis, dis + n, inf);
  fill(dis2, dis2 + n, inf);
  dis[0] = 0;
  pq.push(P(0, 0));
  while (!pq.empty()) {
    P p = pq.top();
    pq.pop();
    int v = p.second, d = p.first;
    if (dis2[v] < d)
      continue;
    for (int i = 0; i < a[v].size(); i++) {
      edge e = a[v][i];
      int d2 = d + e.cost;
      if (dis[e.to] > d2) {
        swap(dis[e.to], d2);
        pq.push(P(dis[e.to], e.to));
      }
      if (dis2[e.to] > d2 && dis[e.to] < d2) {
        dis2[e.to] = d2;
        pq.push(P(dis2[e.to], e.to));
      }
    }
  }
  cout << dis2[n - 1] << endl;
}