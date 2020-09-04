/*
Problem: https://leetcode.com/problems/binary-tree-maximum-path-sum/

Approach: Traverse the binary tree on a DFS fashion, returning the maximum path for each node
        that could be one of the three possibilites (node, node + maxright, node + maxleft).
        And also its important to verify if (node + maxright + maxleft) is the maxmium path, 
        but this path would not be returned, because we are returning paths not finished.

Time complexity: O(n)

Space complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <climits>

#include "../../Common/BinaryTree.h"

using namespace std;
using namespace SweCommmon;

int doDfs(TreeNode<int>* node, int &_max) {
    if (node == nullptr) {
        return 0;
    }
    int maxLeft = doDfs(node->left, _max);
    int maxRight = doDfs(node->right, _max);
    int maxReturn = max(node->val, max(maxLeft + node->val, maxRight + node->val));
    _max = max(_max, max(maxReturn, maxLeft + maxRight + node->val));
    return maxReturn;
}

int maxPathSum(TreeNode<int>* root) {
    int _max = INT_MIN;
    doDfs(root, _max);
    return _max;
}

int main() {
    TreeNode<int> *root = new TreeNode<int>(-10);
    root->left = new TreeNode<int>(9);
    root->right = new TreeNode<int>(20);
    root->right->left = new TreeNode<int>(15);
    root->right->right = new TreeNode<int>(7);

    printTree(root);

    cout << maxPathSum(root) << endl;

    deleteTree(root);

    return 0;
}
