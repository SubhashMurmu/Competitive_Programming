#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> prefixsumBit(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> temp(n + 1, vector<int>(32, 0));

    // Step 1: Store bit information in 'temp'
    for (int i = 1; i <= n; ++i) {
        int num = nums[i - 1];
        for (int j = 0; j < 32; ++j) {
            // Check if the j-th bit of nums[i] is set
            if ((1 << j) & num) {
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

int rangeBitwiseOR(vector<vector<int>>& psum, int l, int r) {
    int result = 0;
    for (int j = 0; j < 32; ++j) {
        // Calculate the count of elements with j-th bit set
        // in the range [l, r]
        int count = psum[r][j] - psum[l - 1][j];

        // If at least one element in the range has j-th bit
        // set, add it to the result
        if (count > 0) {
            result += (1 << j);
        }
    }
    return result;
}

// Driver's code
int main() {
    // Input Array
    vector<int> nums = {13, 11, 2, 3, 6};
    // Range
    int l = 2, r = 4;
    // 2D prefix sum
    vector<vector<int>> psum = prefixsumBit(nums);
    cout << "Bitwise OR of range [2,4] is: " << rangeBitwiseOR(psum, l, r) << endl;

    return 0;
}
