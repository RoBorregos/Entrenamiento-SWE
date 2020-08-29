/*
Problem: https://leetcode.com/problems/move-zeroes/

Approach: Keep an index of the last non zero and do only a swap when
            necessary.

Time complexity: O(n)

Space complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int last_non_zero = 0;
    for (int index = 0; index < nums.size(); ++index) {
        if (nums[index]) {
            swap(nums[last_non_zero], nums[index]);
            ++last_non_zero;
        }
    }
}

void print(const string& text, const vector<int>& nums) {
    cout << text;
    for (const auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> test = {7, 1, 5, 3, 0, 6, 4};
    print("Original: ", test);

    moveZeroes(test);
    print("Zeroes moved: ", test);
    return 0;
}
