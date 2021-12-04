#include "testlib.h"
#include <set>

using namespace std;

int main() {
  registerValidation();

  int N = inf.readInt(2, 1000000, "Races");
  inf.readEoln();

  
  set<int> ts;
  for (int i = 1; i <= N; ++i) {
    int t = inf.readInt(1, 1000000000, "Time");
    ts.insert(t);
    if (i != N) inf.readSpace();
  }
  ensuref(ts.size() >= 2, "Should have at least 2 distinct times.");
  inf.readEoln();
  inf.readEof();
}
