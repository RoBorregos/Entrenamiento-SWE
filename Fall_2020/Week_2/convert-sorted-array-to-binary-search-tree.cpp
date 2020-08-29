/*
Problem: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

Approach: Do like a binary search, and depending on whether you went left or right is where
            you will be pushing the node.

Time complexity: O(n)

Space complexity: O(n)
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

TreeNode *createTree(const vector<int> &nums, const int min, const int max) {
    const int mid = (max + min) / 2;

    if (min > max) return nullptr;

    TreeNode *root = new TreeNode(nums[mid]);
    root->left = createTree(nums, min, mid - 1);
    root->right = createTree(nums, mid + 1, max);
    return root;
}

TreeNode *sortedArrayToBST(const vector<int> &nums) { return createTree(nums, 0, nums.size() - 1); }

int main() {
    const vector<int> &nums = {-10, -3, 0, 5, 9};

    deleteTree(sortedArrayToBST(nums));

    return 0;
}
