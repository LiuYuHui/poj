#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int maxn = 21;
const int inf = 1e8;

pair<int, int> a[maxn];

int need[maxn];

int main() {
  int n, c;
  scanf("%d%d", &n, &c);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i].first, &a[i].second);
  }
  int week = 0;
  for (int i = 0; i < n; i++) {
    if (a[i].first >= c) {
      week += a[i].second;
      a[i].second = 0;
    }
  }
  sort(a, a + n, greater<pair<int, int>>());

  while (true) {
    int sum = c;
    memset(need, 0, sizeof(need));
    for (int i = 0; i < n; i++) {
      if (sum > 0 && a[i].second > 0) {
        int t = min(sum / a[i].first, a[i].second);
        sum -= t * a[i].first;
        need[i] = t;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (sum > 0 && a[i].second > 0) {
        int t = min((sum + a[i].first - 1) / a[i].first, a[i].second - need[i]);
        sum -= t * a[i].first;
        need[i] += t;
      }
    }
    if (sum > 0)
      break;
    int minsecond = inf;
    for (int i = 0; i < n; i++) {
      if (need[i] != 0) {
        minsecond = min(minsecond, a[i].second / need[i]);
      }
    }
    week += minsecond;
    for (int i = 0; i < n; i++) {
      if (need[i] != 0) {
        a[i].second -= minsecond * need[i];
      }
    }
  }
  cout << week << endl;
}