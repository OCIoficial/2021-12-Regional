#include <iostream>

using namespace std;

int main() {
    int n, t, t1 = 1000000001, t2 = 1000000002;

    ios_base::sync_with_stdio(false);

    cin >> n;

    while (n--) {
        cin >> t;
        if (t < t1) {
            t2 = t1;
            t1 = t;
        } else if (t > t1 && t < t2) {  // Descartamos t == t1
            t2 = t;
        }
    }

    cout << t2 << endl;

    return 0;
}
