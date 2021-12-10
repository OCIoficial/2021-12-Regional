#include <cstdio>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  int g = 0, j = 0, max_g = 0, max_j = 0, max_k = 0;
  for (int i = 1; i <= n; ++i) {
    int ci, pi, ki, vi;
    scanf("%d%d%d%d", &ci, &pi, &ki, &vi);
    int b = ki * vi - ci * pi;
    if (g + b >= 0) {
      g += b;

      if (g > max_g || (g == max_g && i - j > max_k - max_j)) {
        max_g = g;
        max_j = j + 1;
        max_k = i;
      }
    } else {
      g = 0;
      j = i;
    }
  }

  if (max_g > 0) {
    printf("%d %d %d\n", max_j, max_k, max_g);
  } else {
    printf("IMPOSIBLE\n");
  }
}
