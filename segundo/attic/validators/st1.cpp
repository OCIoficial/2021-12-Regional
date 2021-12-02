#include "testlib.h"
#include <set>

using namespace std;

int main() {
  registerValidation();

  int N = inf.readInt(2, 3, "Caballos");
  inf.readEoln();

  
  set<int> ts;
  for (int i = 1; i <= N; ++i) {
    int t = inf.readInt(1, 1000000000, "Tiempo");
    ensuref(ts.find(t) == ts.end(), "Numbers must be unique.");
    ts.insert(t);
    if (i != N) inf.readSpace();
  }
  inf.readEoln();
  inf.readEof();
}
