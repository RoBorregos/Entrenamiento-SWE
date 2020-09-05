/*
Problem: https://leetcode.com/problems/maximum-depth-of-binary-tree/

Approach: Traverse the binary tree on a DFS fashion and keep track of the maximum depth.

Time complexity: O(n)

Space complexity: O(1)
*/

#include <iostream>
#include <vector>
#include "../../Common/BinaryTree.h"

using namespace std;
using namespace SweCommmon;

int maxDepth(TreeNode<int> *root, const int depth) {
    if (root == nullptr) {
        return depth;
    }
    return max(maxDepth(root->left, depth + 1), maxDepth(root->right, depth + 1));
}

int maxDepth(TreeNode<int> *root) { return maxDepth(root, 0); }

int main() {
    TreeNode<int> *root = new TreeNode<int>(3);
    root->left = new TreeNode<int>(9);
    root->right = new TreeNode<int>(20);
    root->right->left = new TreeNode<int>(15);
    root->right->right = new TreeNode<int>(7);

    printTree(root);

    cout << maxDepth(root) << endl;

    deleteTree(root);

    return 0;
}
