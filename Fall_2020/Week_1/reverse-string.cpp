/*
Problem: https://leetcode.com/problems/reverse-string/description/

Approach: Traverse the string using two pointers which will meet in the middle,
            and during each iteration, swap the contents of the two pointers.

Time complexity: O(n)

Space complexity: O(1)

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        swap(s[i], s[j]);
    }
}

void print(const string initial_text, const vector<char>& str) {
    cout << initial_text;
    for (const auto c : str) {
        cout << c;
    }
    cout << endl;
}

int main() {
    vector<char> test = {'a', 'b', 'c', 'd', 'e', 'f'};

    print("Original: ", test);

    reverseString(test);

    print("Reversed: ", test);

    return 0;
}
