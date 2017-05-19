#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int maxn = 9;
int a[maxn][maxn];

bool used[maxn];

int n, k, ans;
void dfs(int i, int num) {
  if (num == k) {
    ans++;
    return;
  }
  if (i == n)
    return;
  for (int j = 0; j < n; j++) {
    if (a[i][j] == 1 && !used[j]) {
      used[j] = true;
      dfs(i + 1, num + 1);
      used[j] = false;
    }
  }
  dfs(i + 1, num);
}
int main() {
  while (scanf("%d%d", &n, &k) > 0 && n != -1 && k != -1) {
    ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        char c;
        //  scanf("%c", &c);
        cin >> c;
        if (c == '#')
          a[i][j] = 1;
        else
          a[i][j] = 0;
      }
    memset(used, false, sizeof(used));

    dfs(0, 0);
    printf("%d\n", ans);
  }
}