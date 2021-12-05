#include "testlib.h"

using namespace std;

int main() {
  registerValidation();

  int D = inf.readInt(0, 6, "Day of week for start of month");
  inf.readSpace();
  int X = inf.readInt(1, 30, "Initial day");
  inf.readEoln();
  inf.readEof();
}
