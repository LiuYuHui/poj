#include <algorithm>
#include <cstdio>
#include <iostream>
#include<cmath>
using namespace std;
const int maxn = 12;
const int inf = 1e9;
int m;
int a[maxn];
int slove() {
  while (a[0] == 0)
    next_permutation(a, a + m);
  int n = m / 2;
  int minVal = inf;
  do {
    if (a[n]) {
      int d = 0, d2 = a[n];
      for (int i = 0; i < n; i++) {
        d = d * 10 + a[i];
      }
      for (int i = n + 1; i < m; i++) {
        d2 = d2 * 10 + a[i];
      }
      minVal = min(abs(d2 - d), minVal);
    }

  } while (next_permutation(a, a + m));
  return minVal;
}
int main() {
  int k;
  scanf("%d", &k);
  while (k--) {
    m=0;
    char c;
    int tmp;
    while (scanf("%d%c", &tmp, &c) != EOF) {
      a[m++] = tmp;
      if (c == '\n')
        break;
    }
    if (m == 1)
      printf("%d\n", a[0]);
    else if (m == 2)
      printf("%d\n", abs(a[0] - a[1]));
    else
      printf("%d\n", slove());
  }
}