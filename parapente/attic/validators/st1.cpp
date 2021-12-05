#include "testlib.h"

using namespace std;

int main() {
  registerValidation();

  int M = inf.readInt(1, 1, "Rows");
  inf.readSpace();
  int N = inf.readInt(1, 1000, "Columns");
  inf.readEoln();

  for (int i = 1; i <= M; ++i) {
    for (int j = 1; j <= N; ++j) {
      int A = inf.readInt(1, 1000000000, "Height");
      if (j != N) inf.readSpace();
    }
    inf.readEoln();
  }
  inf.readEof();
}
