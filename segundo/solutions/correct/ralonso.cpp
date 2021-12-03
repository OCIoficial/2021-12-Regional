#include <iostream>

using namespace std;

int main() {
    int n, t, t1 = 0, t2 = 0, i1, i2;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> t;
        if (t <= t1) {
            t2 = t1;
            i2 = i1;
            t1 = t;
            i1 = i;
        } else if (t <= t2) {
            t2 = t;
            i2 = i;
        }
    }

    cout << i2 << endl;

    return 0;
}
