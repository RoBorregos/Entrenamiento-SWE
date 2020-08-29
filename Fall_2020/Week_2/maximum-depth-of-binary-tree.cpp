/*
Problem: https://leetcode.com/problems/maximum-depth-of-binary-tree/

Approach: Traverse the binary tree on a DFS fashion and keep track of the maximum depth.

Time complexity: O(n)

Space complexity: O(1)
*/

#include <iostream>
#include <vector>

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

int maxDepth(TreeNode *root, const int depth) {
    if (root == nullptr) {
        return depth;
    }
    return max(maxDepth(root->left, depth + 1), maxDepth(root->right, depth + 1));
}

int maxDepth(TreeNode *root) { return maxDepth(root, 0); }

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << maxDepth(root) << endl;

    deleteTree(root);

    return 0;
}
