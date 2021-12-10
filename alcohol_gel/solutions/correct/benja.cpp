#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> balance(n);
    for (int i = 0; i < n; i++) {
        int c, p, k, v;
        cin >> c >> p >> k >> v;
        int b = (k * v) - (c * p);
        balance[i] = b;
    }

    int current = 0, best_i, best_j, best_b = -100000;
    int start = -1, end;
    for (int i = 0; i < n; i++) {
        current += balance[i];
        if (start == -1 && current >= 0) {
            start = i;
        }
        if (current > 0) {
            end = i;
        }
        if (current > best_b || (current == best_b && best_j - best_i < end - start)) {
            best_b = current;
            best_i = start;
            best_j = end;
        }
        if (current < 0) {
            start = -1;
            current = 0;
        }
    }

    if (best_b > 0) {
        cout << best_i + 1 << " " << best_j + 1 << " " << best_b << endl;
    }
    else {
        cout << "IMPOSIBLE\n";
    }
}