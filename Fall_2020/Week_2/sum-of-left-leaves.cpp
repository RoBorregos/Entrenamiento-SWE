/*
Problem: https://leetcode.com/problems/sum-of-left-leaves/

Approach: Use DFS and keep track from where did you access it; left or right.

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

int realSum(TreeNode *root, bool bSum) {
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

int sumOfLeftLeaves(TreeNode *root) {
    int iL = 0;
    if (root) {
        if (root->left) iL += realSum(root->left, true);
        if (root->right) iL += realSum(root->right, false);
    }
    return iL;
}

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << sumOfLeftLeaves(root) << endl;

    deleteTree(root);

    return 0;
}
