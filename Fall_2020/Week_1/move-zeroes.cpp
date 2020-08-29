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

int main() {
    vector<int> test = {7, 1, 5, 3, 0, 6, 4};
    cout << moveZeroes(test) << endl;
    return 0;
}