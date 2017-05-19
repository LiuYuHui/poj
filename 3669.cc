#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
const int maxn = 300 + 10;
const int inf = 1e9;
int a[maxn][maxn];
bool vis[maxn][maxn];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
struct point {
  int x, y, t;
  point(int x, int y, int t) : x(x), y(y), t(t) {}
};
int m;
int bfs() {
  memset(vis, false, sizeof(vis));
  vis[0][0] = true;
  queue<point> q;
  q.push(point(0, 0, 0));
  while (!q.empty()) {
    point tmp = q.front();
    q.pop();
    if (a[tmp.y][tmp.x] == inf)
      return tmp.t;
    for (int i = 0; i < 4; i++) {
      int nx = tmp.x + dx[i];
      int ny = tmp.y + dy[i];
      if (nx >= 0 && nx < m && ny >= 0 && ny < m && !vis[ny][nx]) {
        if (tmp.t + 1 < a[ny][nx]) {
          vis[ny][nx] = true;
          q.push(point(nx, ny, tmp.t + 1));
        }
      }
    }
  }
  return -1;
}

int main() {
  int x, y, t;
  fill(a[0], a[0] + maxn * maxn, inf);
  scanf("%d", &m);
  for (int j = 0; j < m; j++) {
    scanf("%d%d%d", &x, &y, &t);
    a[y][x] = min(a[y][x], t);
    for (int i = 0; i < 4; i++) {
      int nx = dx[i] + x;
      int ny = dy[i] + y;
      if (nx >= 0 && nx < m && ny >= 0 && ny < m)
        a[ny][nx] = min(a[ny][nx], t);
    }
  }
  printf("%d\n", bfs());
}