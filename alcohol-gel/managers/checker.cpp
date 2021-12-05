#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int wrong_ans() {
  cout << "0.0\n";
  return 0;
}

int right_ans() {
  cout << "1.0\n";
  return 0;
}

int main(int argc, char *argv[]) {
  ifstream fin;   // Input
  ifstream fcorr; // Expected
  ifstream ftest; // Submission

  fin.open(argv[1]);
  fcorr.open(argv[2]);
  ftest.open(argv[3]);

  if (argc < 4) {
    cerr << "Missing parameter. Please contact contest administrator.\n";
    return -1;
  }

  if (!fin.is_open()) {
    cerr << "Could not open file \"" << argv[1]
         << "\". Please contact contest administrator.\n";
    return 1;
  }

  if (!fcorr.is_open()) {
    cerr << "Could not open file \"" << argv[2]
         << "\". Please contact contest administrator.\n";
    return 2;
  }

  if (!ftest.is_open()) {
    cerr << "Could not open file \"" << argv[3]
         << "\". Please contact contest administrator.\n";
    return 3;
  }

  // Read vector
  int n;
  fin >> n;
  std::vector<int> balance(n);
  for (int i = 0; i < n; ++i) {
    int c, p, k, v;
    fin >> c >> p >> k >> v;
    balance[i] = k * v - c * p;
  }

  int corr_j = -1, corr_k = -1, corr_g = -1;
  fcorr >> corr_j >> corr_k >> corr_g;

  // La respuesta correcta no tiene 3 enteros así que estamos en el caso
  // IMPOSIBLE
  if (corr_j == -1 || corr_k == -1 || corr_g == -1) {
    string output;
    getline(ftest, output);
    return (output == "IMPOSIBLE") ? right_ans() : wrong_ans();
  } else {
    int test_j = -1, test_k = -1, test_g = -1;
    ftest >> test_j >> test_k >> test_g;

    // El output no contiene tres enteros
    if (test_j == -1 || test_k == -1 || test_g == -1) {
      return wrong_ans();
    }

    // El output tiene una ganancia incorrecta
    if (test_g != corr_g) {
      return wrong_ans();
    }

    // El output tiene una ganancia correcta pero de largo distinto
    if (test_k - test_j != corr_k - corr_j) {
      return wrong_ans();
    }

    // Chequear si el periodo contiene la ganancia correcta
    int g = 0;
    for (int i = test_j - 1; i < test_k; ++i) {
      g += balance[i];
    }

    if (g == test_g) {
      return right_ans();
    } else {
      return wrong_ans();
    }
  }
}
