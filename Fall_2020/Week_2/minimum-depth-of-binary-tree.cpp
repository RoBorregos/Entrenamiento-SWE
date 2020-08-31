/*
Problem: https://leetcode.com/problems/minimum-depth-of-binary-tree/

Approach: Traverse the binary tree on a DFS fashion and keep track of the minimum depth.

Time complexity: O(n)

Space complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <climits>

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

int minDepth(TreeNode *root, const int depth) {
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

int minDepth(TreeNode *root) { return root ? minDepth(root, 1) : 0; }

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << minDepth(root) << endl;

    deleteTree(root);

    return 0;
}
