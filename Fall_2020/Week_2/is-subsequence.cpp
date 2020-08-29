/*
Problem: https://leetcode.com/problems/first-unique-character-in-a-string/

Approach: Iterate through both strings, and check if the characters match. If so, move the pointer
            of the subsequent string. At the end, if the pointer has reached the end of the string
            it means that it is subsequent.

Time complexity: O(n)

Space complexity: O(1)
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
