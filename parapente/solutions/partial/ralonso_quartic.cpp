// @ocimatic should-fail=[st2]
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    int result = -1;

    cin >> m >> n;

    vector<vector <int>> a(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = i; k < m; ++k) {
                for (int l = j; l < n; ++l) {
                    if (k == i && l == j) continue;
                    if (a[i][j] <= a[k][l]) continue;
                    if (a[i][j] - a[k][l] > result) {
                        result = a[i][j] - a[k][l];
                    }
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}
