#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int n;
const int mx = 20000 + 10;
int a[mx];
int main() {
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    pq.push(tmp);
  }
  long long res = 0;
  while (pq.size() > 1) {
    int m1 = pq.top();
    pq.pop();
    int m2 = pq.top();
    pq.pop();
    pq.push(m1 + m2);
    res += (m1 + m2);
  }
  cout << res << endl;
}