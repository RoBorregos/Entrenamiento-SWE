/*
Problem: https://leetcode.com/problems/validate-binary-search-tree/

Approach: Use DFS and keep track of the range of values permited on each subtree.

Time complexity: O(n)

Space complexity: O(n)
*/

#include <climits>
#include <iostream>
#include <queue>
#include <vector>

#include "../../Common/BinaryTree.h"

using namespace std;
using namespace SweCommmon;

bool isValid(TreeNode<int> *root, const int64_t min_val, const int64_t max_val) {
    return root == nullptr ||((root->val < max_val && root->val > min_val) &&
        isValid(root->left, min_val, root->val) && isValid(root->right, root->val, max_val));
}

bool isValidBST(TreeNode<int> *root) {
    return root == nullptr ||
           (isValid(root->left, LONG_MIN, root->val) && isValid(root->right, root->val, LONG_MAX));
}

int main() {
    TreeNode<int> *root = new TreeNode<int>(3);
    root->left = new TreeNode<int>(9);
    root->right = new TreeNode<int>(20);
    root->right->left = new TreeNode<int>(15);
    root->right->right = new TreeNode<int>(7);

    printTree(root);

    if (isValidBST(root)) {
        cout << "Is valid" << endl;
    } else {
        cout << "Is not valid" << endl;
    }

    deleteTree(root);

    return 0;
}
