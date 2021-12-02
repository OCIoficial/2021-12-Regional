#include "testlib.h"

using namespace std;

int main() {
  registerValidation();

  int N = inf.readInt(2, 3, "Caballos");
  inf.readEoln();

  for (int i = 1; i <= N; ++i) {
    int t = inf.readInt(1, 1000000000, "Tiempo");
    if (i != N) inf.readSpace();
  }
  inf.readEoln();
  inf.readEof();
}
