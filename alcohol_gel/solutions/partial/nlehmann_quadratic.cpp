#include <climits>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  vector<int> sums(n + 1);
  for (int i = 0; i < n; ++i) {
    int c, p, k, v;
    scanf("%d%d%d%d", &c, &p, &k, &v);
    sums[i + 1] = sums[i] + (k * v - c * p);
  }

  int max_g = INT_MIN, max_k = -1, max_j = -1;
  for (int j = 0; j < n; ++j) {
    for (int k = j; k < n; ++k) {
      int sum = sums[k + 1] - sums[j];
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
