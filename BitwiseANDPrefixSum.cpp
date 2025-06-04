#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> prefixsumBit(vector<int>& nums) {
    int n = nums.size();

    // Step 1: Store bit information in 'temp'
    vector<vector<int>> temp(n + 1, vector<int>(32, 0));
    for (int i = 1; i <= n; ++i) {
        int num = nums[i - 1]; // Fix indexing error
        for (int j = 0; j < 32; ++j) {
            // Check if the j-th bit of nums[i] is set
            if (((1 << j) & num) != 0) { // Fix indexing error
                temp[i][j] = 1;
            }
        }
    }

    // Step 2: Compute prefix sums
    vector<vector<int>> psum(n + 1, vector<int>(32, 0));
    for (int j = 0; j < 32; ++j) {
        for (int i = 1; i <= n; ++i) {
            // Calculate prefix sum for each bit
            psum[i][j] = psum[i - 1][j] + temp[i][j];
        }
    }
    return psum;
}

int rangeBitwiseAND(vector<vector<int>>& psum, int l, int r) {
    int result = 0;
    for (int j = 0; j < 32; ++j) {
        // Calculate the count of elements with j-th bit set
        // in the range [l, r]
        int count = psum[r][j] - psum[l - 1][j];
        if (count == r - l + 1) {
            // If all elements in the range have j-th bit
            // set, add it to the result
            result = result + (1 << j);
        }
    }
    return result;
}

// driver's code
int main() {
    // Input Array
    vector<int> nums = { 13, 11, 2, 3, 6 };

    // Range
    int l = 2, r = 4;

    // 2D prefix sum
    vector<vector<int>> psum = prefixsumBit(nums);

    cout << "Bitwise AND of range [2,4] is: " << rangeBitwiseAND(psum, l, r);

    return 0;
}
