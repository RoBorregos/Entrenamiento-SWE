/*
Problem: https://leetcode.com/problems/maximum-depth-of-binary-tree/

Approach: Traverse the binary tree on a DFS fashion and keep track of the maximum depth.

Time complexity: O(n)

Space complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode() { cout << "Deleted the node: " << val << endl; }
};

void deleteTree(TreeNode *root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int doDfs(TreeNode* node, int &_max){
    if (node == nullptr) {
        return 0;
    }
    int maxLeft = doDfs(node->left, _max);
    int maxRight = doDfs(node->right, _max);
    int maxReturn = max(node->val, max(maxLeft + node->val, maxRight + node->val));
    _max = max(_max, max(maxReturn, maxLeft + maxRight + node->val));
    return maxReturn;
}

int maxPathSum(TreeNode* root) {
    int _max = INT_MIN;
    doDfs(root, _max);
    return _max;
}

int main() {
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << maxPathSum(root) << endl;

    deleteTree(root);

    return 0;
}
