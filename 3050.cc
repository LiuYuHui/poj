#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
const int maxn = 6;
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

set<int> s;
int a[maxn][maxn];
void dfs(int x, int y, int n, int k) {
  if (6 == k) {
    s.insert(n);
    return;
  }
  for (int i = 0; i < 4; i++) {
    int nx = dx[i] + x;
    int ny = dy[i] + y;
    if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
      k++;
      dfs(nx, ny, 10 * n + a[nx][ny], k);
      k--;
    }
  }
}
int main() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      dfs(i, j, a[i][j], 1);
    }
  }
  cout << s.size() << endl;
}