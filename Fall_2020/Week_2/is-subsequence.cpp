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

bool isSubsequence(const string& s, const string& t) {
    int s_index = 0, t_index = 0;
    while (s_index < s.length() && t_index < t.length()) {
        if (s[s_index] == t[t_index]) {
            ++s_index;
        }
        ++t_index;
    }
    return s_index == s.length();
}

int main() {
    const string s = "abc";
    const string t = "ajhjdfgbkjoasdlf";

    if (isSubsequence(s, t)) {
        cout << "It is subsequent" << endl;
    } else {
        cout << "It is not" << endl;
    }

    return 0;
}
