#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int maxn = 31;
char a[maxn][maxn][maxn];
bool used[maxn][maxn][maxn];
int dx[6] = {0, 0, -1, 1, 0, 0}, dy[6] = {0, 0, 0, 0, -1, 1},
    dz[6] = {-1, 1, 0, 0, 0, 0};
struct point {
  int x, y, z, t;
  point(int x, int y, int z, int t) : x(x), y(y), z(z), t(t) {}
};
int l, r, c;
int mx, my, mz;

int bfs(int x, int y, int z) {
  queue<point> q;
  q.push(point(x, y, z, 0));
  used[x][y][z] = true;
  while (!q.empty()) {
    point tmp = q.front();
    q.pop();
    if (tmp.x == mx && tmp.y == my && tmp.z == mz)
      return tmp.t;
    for (int i = 0; i < 6; i++) {
      int nx = tmp.x + dx[i];
      int ny = tmp.y + dy[i];
      int nz = tmp.z + dz[i];
      if (nx >= 0 && nx < l && ny >= 0 && ny < r && nz >= 0 && nz < c &&
          !used[nx][ny][nz]) {
        if (a[nx][ny][nz] != '#') {
          used[nx][ny][nz] = true;
          q.push(point(nx, ny, nz, tmp.t + 1));
        }
      }
    }
  }
  return -1;
}

int main() {
  int sx, sy, sz;
  while (cin >> l >> r >> c && l != 0) {
    memset(used, false, sizeof(used));
    for (int i = 0; i < l; i++)
      for (int j = 0; j < r; j++) {
        for (int k = 0; k < c; k++) {
          cin >> a[i][j][k];
          if (a[i][j][k] == 'S') {
            sx = i, sy = j, sz = k;
          } else if (a[i][j][k] == 'E') {
            mx = i, my = j, mz = k;
          }
        }
      }
    int ans = bfs(sx, sy, sz);
    if (ans > 0)
      printf("Escaped in %d minute(s).\n", ans);
    else
      printf("Trapped!\n");
  }
}