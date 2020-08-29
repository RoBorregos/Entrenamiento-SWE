/*
Problem: https://leetcode.com/problems/validate-binary-search-tree/

Approach: Use DFS and keep track of the range of values permited on each subtree.

Time complexity: O(n)

Space complexity: O(n)
*/

#include <iostream>
#include <queue>
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

bool isValid(TreeNode *root, const int64_t min_val, const int64_t max_val) {
    return root == nullptr ||
           ((root->val < max_val && root->val > min_val) &&
            isValid(root->left, min_val, root->val) && isValid(root->right, root->val, max_val));
}

bool isValidBST(TreeNode *root) {
    return root == nullptr ||
           (isValid(root->left, LONG_MIN, root->val) && isValid(root->right, root->val, LONG_MAX));
}

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    if (isValidBST(root)) {
        cout << "Is valid" << endl;
    } else {
        cout << "Is not valid" << endl;
    }

    deleteTree(root);

    return 0;
}
