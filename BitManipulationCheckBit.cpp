// Check if the bit at position pos in number n is set (1) or unset (0)
bool isBitSet(int n, int pos) {
    return ((n & (1 << pos)) != 0);
}
