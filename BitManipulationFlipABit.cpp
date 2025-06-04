// Flip (toggle) a bit at position pos in number n
void flip(int &n, int pos) {
    n ^= (1 << pos);
}
