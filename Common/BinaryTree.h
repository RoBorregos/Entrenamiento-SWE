#ifndef COMMON_BINARYTREE_H_
#define COMMON_BINARYTREE_H_

#include <iostream>

namespace SweCommmon {

// TreeNode simple structure.
template <typename T>
struct TreeNode {
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(NULL), left(nullptr), right(nullptr) {}
    explicit TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(T x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode() { std::cout << "Deleted the node: " << val << std::endl; }
};

// Deletes all the tree starting from root, until it reaches the end.
template <typename T>
void deleteTree(TreeNode<T> *root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

// Prints the binary tree in a user friendly matter.
// space and space_count determine the amount of spaces to leave between level.
template <typename T>
void printTree(TreeNode<T> *root, int space = 0, const int space_count = 10) {
    if (root) {
        space += space_count;
        printTree(root->right, space);
        for (int i = space_count; i < space; ++i) {
            std::cout << " ";
        }
        std::cout << root->val << "\n";
        printTree(root->left, space);
    }
}

}  // namespace SweCommmon

#endif  // COMMON_BINARYTREE_H_
