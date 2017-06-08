#include <algorithm>
#include <iostream>

using namespace std;
const int inf = 1e9;
int main() {
  int n, s;
  int c, y;
  int preMincost = inf;
  long long sum = 0;
  while (cin >> n >> s) {
    for (int i = 0; i < n; i++) {
      cin >> c >> y;
      int mincost = min(preMincost + s, c);
      sum += y * mincost;
      preMincost = mincost;
    }

    cout << sum << endl;
    1
  }
}