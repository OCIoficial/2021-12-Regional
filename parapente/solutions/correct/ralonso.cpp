#include<iostream>
#include<vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<vector<int>> h(m, vector<int>(n));
    vector<vector<int>> dp(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> h[i][j];
        }
    }

    dp[0][0] = 0;
    
    int best = 0;

    for (int i = 1; i < m; ++i) {
        dp[i][0] = max(h[i - 1][0], dp[i - 1][0]);
        if (dp[i][0] - h[i][0] > best)
            best = dp[i][0] - h[i][0];
    }

    for (int j = 1; j < n; ++j) {
        dp[0][j] = max(h[0][j - 1], dp[0][j - 1]);
        if (dp[0][j] - h[0][j] > best)
            best = dp[0][j] - h[0][j];
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = max(
                max(h[i][j - 1], dp[i][j - 1]),
                max(h[i - 1][j], dp[i - 1][j])
            );
            if (dp[i][j] - h[i][j] > best)
                best = dp[i][j] - h[i][j];
        }
    }

    cout << (best ? best : -1) << endl;

    return 0;
}
