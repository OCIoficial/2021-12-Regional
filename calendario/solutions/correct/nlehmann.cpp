#include <algorithm>
#include <cstdio>
#include <functional>
#include <vector>
using namespace std;

int cap(int x) {
  while (x > 30)
    x -= 30;
  return x;
}

int main() {
  int d, x;
  vector<bool> marked(30);

  scanf("%d%d", &d, &x);

  auto week_day = [=](int i) { return (i - 1 + d) % 7; };

  auto mon = [&](int i) {
    int x = cap(i + 1);
    while (marked[x] && x != i) {
      x = cap(x + 1);
    }
    return x;
  };
  auto tue = [](int i) { return 31 - i; };
  auto wed = [](int i) { return i % 2 == 0 ? i - 1 : i + 1; };
  auto thu = [](int i) { return cap(i + 10); };
  auto fri = [](int i) { return i % 2 == 0 ? i / 2 : cap(3 * i + 1); };
  auto sat = [](int i) { return cap(2 * i); };
  auto sun = [&](int i) {
    int x = cap(i + 2);
    while (marked[x] && x != i)
      x = cap(x + 2);
    return x;
  };

  function<int(int)> rules[7] = {mon, tue, wed, thu, fri, sat, sun};

  while (!marked[x]) {
    marked[x] = true;
    x = rules[week_day(x)](x);
  }

  printf("%d\n", x);
}
