#include <iostream>

// Corrected D1 implementation: the threshold is inclusive.
int countAtLeast(int value, int threshold) {
    int count = 0;
    if (value >= threshold) {
        ++count;
    }
    return count;
}

bool check(int value, int threshold, int expected) {
    const int actual = countAtLeast(value, threshold);
    std::cout << "value=" << value << ", threshold=" << threshold
              << ", expected=" << expected << ", actual=" << actual;

    if (actual != expected) {
        std::cout << " -> FAIL\n";
        return false;
    }
    std::cout << " -> PASS\n";
    return true;
}

int main() {
    bool allPassed = true;
    allPassed = check(49, 50, 0) && allPassed;
    allPassed = check(50, 50, 1) && allPassed;
    allPassed = check(51, 50, 1) && allPassed;

    if (!allPassed) {
        std::cerr << "Regression tests failed.\n";
        return 1;
    }

    std::cout << "All D1 regression tests passed.\n";
    return 0;
}
