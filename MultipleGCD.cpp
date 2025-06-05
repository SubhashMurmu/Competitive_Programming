#include <iostream>
#include <numeric>  // for std::gcd
#include <vector>

int findGCD(const std::vector<int>& nums) {
    int result = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        result = std::gcd(result, nums[i]);
    }
    return result;
}

int main() {
    std::vector<int> nums = {36, 60, 24, 12};
    std::cout << "GCD of the numbers is: " << findGCD(nums) << std::endl;
    return 0;
}
