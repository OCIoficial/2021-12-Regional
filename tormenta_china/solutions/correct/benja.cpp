#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    uint32_t n;
    uint64_t smallest = 10000000000, second = 10000000000;
    cin >> n;
    for (int i = 0; i < n; i++) {
        uint64_t current;
        cin >> current;
        if (current < smallest) { 
            second = smallest;
            smallest = current;
        }
        else if (current < second && current != smallest) {
            second = current;
        }
    }
    cout << second << endl;
}
