/*
Problem: https://leetcode.com/problems/find-bottom-left-tree-value/

Approach: Use BFS with a stack and keep track of the level, after finishing a level
            the bottom left most leaf is the index 0.

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

int findBottomLeftValue(TreeNode *root) {
    vector<int> level;
    int bottom_left;

    queue<TreeNode *> nodes_queue;
    int nodes_in_level = 1;
    nodes_queue.push(root);

    while (!nodes_queue.empty()) {
        auto current_node = nodes_queue.front();
        nodes_queue.pop();

        if (current_node->left) nodes_queue.push(current_node->left);
        if (current_node->right) nodes_queue.push(current_node->right);

        level.push_back(current_node->val);

        if (--nodes_in_level == 0) {
            bottom_left = level[0];
            level.clear();
            nodes_in_level = nodes_queue.size();
        }
    }
    return bottom_left;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->left->left = new TreeNode(7);
    root->right->right = new TreeNode(6);

    cout << findBottomLeftValue(root) << endl;

    deleteTree(root);

    return 0;
}
