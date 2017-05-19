#include <algorithm>
#include <cstdio>
#include <iostream>

const int maxn = 25;
const int inf = (1 << 28);
int a[maxn][maxn];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int w, h;
int minStep;
int currStep;
void dfs(int x, int y, int depth) {
  if (depth >= 10)
    return;
  if (depth > minStep)
    return;
  for (int i = 0; i < 4; i++) {
    int nx = x, ny = y;
    while (nx >= 0 && nx < w && ny >= 0 && ny < h && a[nx][ny] == 0) {
      nx += dx[i], ny += dy[i];
    }
    if (nx >= 0 && nx < w && ny >= 0 && ny < h && a[nx][ny] == 3) {
      minStep = min(minStep, depth + 1);
    } else if (!(nx - dx[i] == x && ny - dy[i] == y)) {
      if (nx >= 0 && nx < w && ny >= 0 && ny < h && a[nx][ny] == 1) {
        a[nx][ny] = 0;
        dfs(nx - dx[i], ny - dy[i], depth + 1);
        a[nx][ny] = 1;
      }
    }
  }
}
int main() {
  int sx, sy, gx, gy;
  while (cin >> w >> h && w > 0) {
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> a[j][i];
        if (a[j][i] == 2) {
          a[j][i] = 0;
          sx = j, sy = i;
        }
      }
    }
    minStep = inf;
    dfs(sx, sy, 0);
    printf("%d\n", (minStep == inf) ? -1 : minStep);
  }
}