#include <climits>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  vector<int> balances;
  for (int i = 0; i < n; ++i) {
    int c, p, k, v;
    scanf("%d%d%d%d", &c, &p, &k, &v);
    balances.push_back(k * v - c * p);
  }

  int max_g = INT_MIN, max_k = -1, max_j = -1;
  for (int j = 0; j < n; ++j) {
    for (int k = j; k < n; ++k) {
      int sum = 0;
      for (int i = j; i <= k; ++i) {
        sum += balances[i];
      }
      if (sum > max_g || (sum == max_g && k - j > max_k - max_j)) {
        max_g = sum;
        max_k = k;
        max_j = j;
      }
    }
  }

  if (max_g > 0) {
    printf("%d %d %d\n", max_j + 1, max_k + 1, max_g);
  } else {
    printf("IMPOSIBLE\n");
  }
}
