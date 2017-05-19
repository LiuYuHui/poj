#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
const int maxn = 20;
int a[maxn][maxn];
int ans[maxn][maxn];
int m, n;
bool guess() {
  for (int i = 1; i < m; i++) {
    for (int j = 1; j <= n; j++) {
      ans[i + 1][j] = (a[i][j] + ans[i][j] + ans[i - 1][j] + ans[i][j - 1] +
                       ans[i][j + 1]) %
                      2;
    }
  }
  for (int j = 1; j <= n; j++) {
    if ((ans[m][j - 1] + ans[m][j] + ans[m][j + 1] + ans[m - 1][j]) % 2 !=
        a[m][j])
      return false;
  }
  return true;
}
void enumerate() {
  for (int j = 0; j < n + 1; j++) {
    ans[1][j] = 0;
  }
  while (guess() == false) {
    ans[1][1]++;
    int c = 1;
    while (ans[1][c] > 0) {
      ans[1][c++] = 0;
      ans[1][c]++;
    }
  }
}
int main() {
  cin >> m >> n;
  memset(ans, 0, sizeof(ans));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  enumerate();
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}
