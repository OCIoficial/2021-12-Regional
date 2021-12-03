#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> times(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &times[i]);
    }
    sort(times.begin(), times.end());
    unique(times.begin(), times.end());

    printf("%d\n", times[1]);

    return 0;
}
