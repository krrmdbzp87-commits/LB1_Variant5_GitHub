#include <iostream>

// Intentionally defective version for D1 reproduction.
int countAtLeast(int value, int threshold) {
    int count = 0;
    if (value > threshold) { // BUG: equality with the threshold is excluded.
        ++count;
    }
    return count;
}

int main() {
    const int value = 50;
    const int threshold = 50;
    const int expected = 1;
    const int actual = countAtLeast(value, threshold);

    std::cout << "D1 failing test\n"
              << "value=" << value << ", threshold=" << threshold << "\n"
              << "expected=" << expected << ", actual=" << actual << "\n";

    if (actual != expected) {
        std::cerr << "FAIL: value == threshold must be counted.\n";
        return 1;
    }

    std::cout << "PASS\n";
    return 0;
}
