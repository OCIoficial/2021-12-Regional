#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    int min = 1000000000, max = 0;

    cin >> m >> n;

    vector<vector <int>> a(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] < min) min = a[i][j];
            if (a[i][j] > max) max = a[i][j];
        }
    }

    cout << max - min << endl;

    return 0;
}
