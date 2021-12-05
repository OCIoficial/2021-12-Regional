#include <algorithm>
#include <climits>
#include <cstdio>

int max4(int a, int b, int c, int d) {
  return std::max(std::max(a, b), std::max(c, d));
}

int main() {
  int M, N;
  scanf("%d%d", &M, &N);

  int sol = INT_MIN;
  int maxs[M][N];
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      int A;
      scanf("%d", &A);
      maxs[i][j] = A;
      maxs[i][j] = std::max(maxs[i][j], i > 0 ? maxs[i - 1][j] : INT_MIN);
      maxs[i][j] = std::max(maxs[i][j], j > 0 ? maxs[i][j - 1] : INT_MIN);
      maxs[i][j] =
          std::max(maxs[i][j], i > 0 && j > 0 ? maxs[i - 1][j - 1] : INT_MIN);

      sol = max4(sol, i > 0 && j > 0 ? maxs[i - 1][j - 1] - A : INT_MIN,
                 i > 0 ? maxs[i - 1][j] - A : INT_MIN,
                 j > 0 ? maxs[i][j - 1] - A : INT_MIN);
    }
  }

  if (sol <= 0) {
    printf("-1\n");
  } else {
    printf("%d", sol);
  }

  return 0;
}
