#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int mx = 100 + 10;
int a[mx];
int n;
bool cmp(int a, int c) { return a > c; }
void solve() {
  double sum = a[0];
  for (int i = 1; i < n; i++) {
    sum = (2 * sqrt(sum * a[i]));
  }
  printf("%.3f\n", sum);
}

int main() {
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n, cmp);
    solve();
  }
}