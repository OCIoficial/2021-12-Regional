#include "testlib.h"
#include <set>

using namespace std;

int main() {
  registerValidation();

  int N = inf.readInt(2, 1000000, "Races");
  inf.readEoln();

  
  set<int> ts;
  int t = inf.readInt(1, 1000000000, "Time");
  ts.insert(t);
  for (int i = 2; i <= N; ++i) {
    inf.readSpace();
    t = inf.readInt(1, 1000000000, "Time");
    ensuref(ts.find(t) == ts.end(), "Duplicate time %d.", t);
    ts.insert(t);
  }
  ensuref(ts.size() >= 2, "Should not happen.");
  inf.readEoln();
  inf.readEof();
}
