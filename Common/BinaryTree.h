#ifndef COMMON_BINARYTREE_H_
#define COMMON_BINARYTREE_H_

#include <iostream>

namespace {
constexpr int kCount = 10;
}  // namespace

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

template <typename T>
void printTree(TreeNode<T> *root, int space = 0) {
    if (root) {
        space += kCount;
        printTree(root->right, space);
        for (int i = kCount; i < space; ++i) {
            std::cout << " ";
        }
        std::cout << root->val << "\n";
        printTree(root->left, space);
    }
}

}  // namespace SweCommmon

#endif  // COMMON_BINARYTREE_H_
