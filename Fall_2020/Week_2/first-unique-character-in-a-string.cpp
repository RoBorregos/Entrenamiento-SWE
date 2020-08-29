/*
Problem: https://leetcode.com/problems/first-unique-character-in-a-string/

Approach: Save the character in a map to check its uniqueness, then iterate over the map to get
            the index. In this case, the index is saved too, but there are other approaches.

Time complexity: O(n)

Space complexity: O(1) (because there's a maximum of 26 characters)
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int firstUniqChar(const string& s) {
    map<char, int> char_index;
    for (int i = 0; i < s.length(); ++i) {
        auto it = char_index.find(s[i]);
        if (it != char_index.end()) {
            it->second = INT_MAX;
        } else {
            char_index[s[i]] = i;
        }
    }

    int min_index = INT_MAX;
    for (const auto& element : char_index) {
        if (element.second < min_index) {
            min_index = element.second;
        }
    }

    return min_index == INT_MAX ? -1 : min_index;
}

int main() {
    const string s = "Leetcode";

    cout << firstUniqChar(s) << endl;

    return 0;
}
