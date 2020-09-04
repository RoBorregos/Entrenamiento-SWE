/*
Problem: https://leetcode.com/problems/minimum-depth-of-binary-tree/

Approach: Traverse the binary tree on a DFS fashion and keep track of the minimum depth.

Time complexity: O(n)

Space complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <climits>
#include "../../Common/BinaryTree.h"

using namespace std;
using namespace SweCommmon;

int minDepth(TreeNode<int> *root, const int depth) {
    int l_min = INT_MAX, r_min = INT_MAX;
    if (root->left) {
        l_min = minDepth(root->left, depth + 1);
    }
    if (root->right) {
        r_min = minDepth(root->right, depth + 1);
    }

    if (root->left == nullptr && root->right == nullptr) {
        return depth;
    } else {
        return min(l_min, r_min);
    }
}

int minDepth(TreeNode<int> *root) { return root ? minDepth(root, 1) : 0; }

int main() {
    TreeNode<int> *root = new TreeNode<int>(3);
    root->left = new TreeNode<int>(9);
    root->right = new TreeNode<int>(20);
    root->right->left = new TreeNode<int>(15);
    root->right->right = new TreeNode<int>(7);

    printTree(root);

    cout << minDepth(root) << endl;

    deleteTree(root);

    return 0;
}
