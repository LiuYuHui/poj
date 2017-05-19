#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

long long bfs(int n) {
  queue<long long> q;
  q.push(1);
  while (!q.empty()) {
    long long tmp = q.front();
    q.pop();
    if (tmp % n == 0)
      return tmp;
    q.push(tmp * 10);
    q.push(tmp * 10 + 1);
  }
  return 0;
}
int main() {
  int n;
  while (cin >> n && n) {
    cout << bfs(n) << endl;
  }
}