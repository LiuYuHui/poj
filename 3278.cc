// something wrong in poj
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
const int maxn = 1e5 + 10;
struct point {
  int x, s;
  point(int x, int t) : x(x), s(t) {}
};
bool used[maxn];
int n, k;
int bfs() {
  queue<point> q;
  q.push(point(n, 0));
  used[n] = true;
  while (!q.empty()) {
    point tmp = q.front();
    q.pop();
    if (tmp.x == k) {
      return tmp.s;
    }
    for (int i = 0; i < 3; i++) {
      int next;
      if (i == 0)
        next = tmp.x - 1;
      else if (i == 1)
        next = tmp.x + 1;
      else
        next = tmp.x * 2;
      if (next >= 0 && next < maxn && !used[next]) {
        q.push(point(next, tmp.s + 1));
        used[next] = true;
      }
    }
  }
}
int main() {
  while (cin >> n >> k) {
    memset(used, false, sizeof(used));
    cout << bfs() << endl;
  }
}