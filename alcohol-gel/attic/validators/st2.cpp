#include "testlib.h"

using namespace std;

int main() {
  registerValidation();

  int N = inf.readInt(1, 5000, "Days");
  inf.readEoln();

  int stock = 0;
  for (int i = 1; i <= N; ++i) {
    int c = inf.readInt(1, 100, "Purchases count");
    inf.readSpace();
    int p = inf.readInt(1, 100, "Purchase price");
    inf.readSpace();
    int k = inf.readInt(1, 100, "Sales count");
    inf.readSpace();
    int v = inf.readInt(1, 100, "Sale price");
    inf.readEoln();
    ensuref(stock + c >= k, "Cannot sell more than available stock.");
    stock += c - k;
  }
  inf.readEof();
}
