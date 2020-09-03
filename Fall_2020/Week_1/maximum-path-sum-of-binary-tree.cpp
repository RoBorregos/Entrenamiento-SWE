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
