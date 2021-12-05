#include <climits>
#include <cstdio>
#include <tuple>
#include <vector>
using namespace std;

struct Sol {
  int i, j, g;
};

bool operator<(const Sol &a, const Sol &b) {
  if (a.g == b.g) {
    return (a.j - a.i) < (b.j - b.i);
  }
  return a.g < b.g;
}

Sol solve(const vector<int> &balance, int i, int j) {
  if (i == j) {
    return {i, j, balance[i]};
  }
  int m = i + (j - i) / 2;

  auto l = solve(balance, i, m);
  auto r = solve(balance, m + 1, j);

  int sum = 0;

  int max_l = INT_MIN, max_l_i = -1;
  for (int k = m; k >= i; --k) {
    sum += balance[k];
    if (sum >= max_l) {
      max_l = sum;
      max_l_i = k;
    }
  }

  sum = 0;
  int max_r = INT_MIN, max_r_i = -1;
  for (int k = m + 1; k <= j; ++k) {
    sum += balance[k];
    if (sum >= max_r) {
      max_r = sum;
      max_r_i = k;
    }
  }

  return std::max(l, std::max(r, {max_l_i, max_r_i, max_l + max_r}));
}

int main() {
  int n;
  scanf("%d", &n);

  vector<int> balance;
  for (int i = 0; i < n; ++i) {
    int c, p, k, v;
    scanf("%d%d%d%d", &c, &p, &k, &v);
    balance.push_back(k * v - c * p);
  }

  auto sol = solve(balance, 0, balance.size() - 1);
  if (sol.g > 0) {
    printf("%d %d %d\n", sol.i + 1, sol.j + 1, sol.g);
  } else {
    printf("IMPOSIBLE\n");
  }
}
