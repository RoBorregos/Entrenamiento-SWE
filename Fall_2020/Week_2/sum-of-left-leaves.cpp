/*
Problem: https://leetcode.com/problems/sum-of-left-leaves/

Approach: Use DFS and keep track from where did you access it; left or right.

Time complexity: O(n)

Space complexity: O(n)
*/

#include <iostream>
#include <queue>
#include <vector>
#include "../../Common/BinaryTree.h"

using namespace std;
using namespace SweCommmon;

int realSum(TreeNode<int> *root, bool bSum) {
    int iL = 0;

    if (root->left) {
        iL += realSum(root->left, true);
    } else if (root->right == NULL && bSum) {
        iL += root->val;
        return iL;
    }

    if (root->right) {
        iL += realSum(root->right, false);
    }
    return iL;
}

int sumOfLeftLeaves(TreeNode<int> *root) {
    int iL = 0;
    if (root) {
        if (root->left) iL += realSum(root->left, true);
        if (root->right) iL += realSum(root->right, false);
    }
    return iL;
}

int main() {
    TreeNode<int> *root = new TreeNode<int>(3);
    root->left = new TreeNode<int>(9);
    root->right = new TreeNode<int>(20);
    root->right->left = new TreeNode<int>(15);
    root->right->right = new TreeNode<int>(7);

    printTree(root);

    cout << sumOfLeftLeaves(root) << endl;

    deleteTree(root);

    return 0;
}
