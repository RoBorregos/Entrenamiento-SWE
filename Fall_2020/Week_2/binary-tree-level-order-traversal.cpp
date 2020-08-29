/*
Problem: https://leetcode.com/problems/binary-tree-level-order-traversal/

Approach: Use BFS with a stack and keep track of the level.

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

void printLevelOrder(const vector<vector<int>> &levels) {
    cout << "level order: " << endl;
    for (const auto &level : levels) {
        for (const auto &node : level) {
            cout << node << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root) {
        return {};
    }

    vector<vector<int>> levels;
    vector<int> level;

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
            levels.push_back(level);
            level.clear();
            nodes_in_level = nodes_queue.size();
        }
    }
    return levels;
}

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    printLevelOrder(levelOrder(root));

    deleteTree(root);

    return 0;
}
