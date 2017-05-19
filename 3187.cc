#include <algorithm>
#include <iostream>

using namespace std;
const int maxn = 10;
int n, sum;
int a[maxn] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int b[maxn];
int slove() {
  do {
    for (int i = 0; i < n; i++) {
      b[i] = a[i];
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < n - i; j++) {
        b[j] = b[j] + b[j + 1];
      }
    }
    if (b[0] == sum)
      break;
  } while (next_permutation(a, a + n));
}
int main() {
  cin >> n >> sum;
  slove();
  for (int i = 0; i < n; i++) {
    if (i != 0)
      cout << " ";
    cout << a[i];
  }
  cout << endl;
}