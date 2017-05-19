#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
const int maxn = 10000;
bool IsPrime[maxn];
int s, e;
bool used[maxn];
struct point {
  int x;
  int s;
  point(int x, int s) : x(x), s(s) {}
};
void sieve(int n) {
  for (int i = 0; i <= n; i++)
    IsPrime[i] = true;
  IsPrime[0] = IsPrime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (IsPrime[i]) {
      for (int j = i * 2; j <= n; j += i)
        IsPrime[j] = false;
    }
  }
}
int bfs() {
  queue<point> q;
  q.push(point(s, 0));
  used[s] = true;
  while (!q.empty()) {
    point tmp = q.front();
    q.pop();
    if (tmp.x == e)
      return tmp.s;
    for (int i = 1; i <= 1000; i *= 10) {
      int num = tmp.x;
      num /= i;
      num %= 10;
      int w = tmp.x - num * i;
      for (int j = 0; j < 10; j++) {
        if (!(i == 1000 && j == 0)) {
          int currNum = w + j * i;
          if (currNum != num && IsPrime[currNum] && !used[currNum]) {
            q.push(point(currNum, tmp.s + 1));
            used[currNum] = true;
          }
        }
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  sieve(maxn);
  while (n--) {
    cin >> s >> e;
    memset(used, false, sizeof(used));
    cout << bfs() << endl;
  }
}