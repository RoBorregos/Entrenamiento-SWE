/*
Problem: https://leetcode.com/problems/trapping-rain-water/

Approach: Use an stack to keep the lowest heights already seen and calculate the area 
          multiplying the lowest height times the difference between the indexes.

Time complexity: O(n)

Space complexity: O(n)
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
        if (height.size() <= 2) {
            return 0;
        }
        stack<pair<int, int>> limit;
        limit.push({0, -1});
        limit.push({height[0], 0});
        int _max = 0, res = 0;
        for (int i = 1; i < height.size(); i++) {
            if (height[i] > height[i-1]) {
                _max = 0;
                while (limit.top().second != -1) {
                    if (i - limit.top().second > 1) {
                        res += (i - limit.top().second - 1)
                            *  (min(height[i], limit.top().first) -_max);
                    }
                    _max = max(_max, limit.top().first);
                    if (limit.top().first > height[i]) {
                        break;
                    }
                    limit.pop();
                }
            }
            limit.push({height[i], i});
        }
        return res;
}

void print(const string& text, const vector<int>& nums) {
    cout << text;
    for (const auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> test = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    print("Original: ", test);

    int result = trap(test);
    cout << "Water Traped: " << result;
    return 0;
}
