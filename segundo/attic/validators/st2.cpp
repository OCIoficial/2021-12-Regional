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
    ensuref(ts.find(t) == ts.end(), "Times must be unique.");
    ts.insert(t);
    if (i != N) inf.readSpace();
  }
  ensuref(ts.size() >= 2, "Should not happen.");
  inf.readEoln();
  inf.readEof();
}
