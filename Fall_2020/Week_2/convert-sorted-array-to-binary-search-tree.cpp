/*
Problem: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

Approach: Do like a binary search, and depending on whether you went left or right is where
            you will be pushing the node.

Time complexity: O(n)

Space complexity: O(n)
*/

#include <iostream>
#include <vector>

#include "../../Common/BinaryTree.h"

using namespace std;
using namespace SweCommmon;

TreeNode<int> *createTree(const vector<int> &nums, const int min, const int max) {
    const int mid = (max + min) / 2;

    if (min > max) return nullptr;

    TreeNode<int> *root = new TreeNode<int>(nums[mid]);
    root->left = createTree(nums, min, mid - 1);
    root->right = createTree(nums, mid + 1, max);
    return root;
}

TreeNode<int> *sortedArrayToBST(const vector<int> &nums) {
    return createTree(nums, 0, nums.size() - 1);
}

int main() {
    const vector<int> &nums = {-10, -3, 0, 5, 9};

    TreeNode<int>* root = sortedArrayToBST(nums);

    printTree(root);

    deleteTree(root);

    return 0;
}
