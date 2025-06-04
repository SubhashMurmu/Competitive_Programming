#include <iostream>

// Unset (clear) a bit at position pos in number n
void unset(int &n, int pos) {
    n &= ~(1 << pos);
}

int main() {
    int n = 15; // 1111 in binary
    int pos = 1;
    unset(n, pos); // Should change n to 13, which is 1101 in binary
    std::cout << n << std::endl; // Output should be 13
    return 0;
}
