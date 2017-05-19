#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 21;
char a[maxn][maxn];
int ans = 0;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int w, h;

int dfs(int &x, int &y) {
  ++ans;
  a[x][y] = '#';
  for (int i = 0; i < 4; i++) {
    int nx = dx[i] + x, ny = dy[i] + y;
    if (nx >= 0 && nx < w && ny >= 0 && ny < h && a[nx][ny] == '.') {
      dfs(nx, ny);
    }
  }
  return ans;
}
int main() {

  int mx, my;
  while (scanf("%d%d", &w, &h) && w > 0) {
    ans = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> a[j][i];
        if (a[j][i] == '@') {
          mx = j;
          my = i;
        }
      }
    }
    printf("%d\n", dfs(mx, my));
  }
}