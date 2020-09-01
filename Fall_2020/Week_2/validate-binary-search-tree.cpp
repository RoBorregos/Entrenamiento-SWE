/*
Problem: https://leetcode.com/problems/validate-binary-search-tree/

Approach: Do a Inorder level in an iterative way using a stack

Time complexity: O(n)

Space complexity: O(n)
*/

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <stack>

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

bool isValidBST(TreeNode* root) {
    if(!root) return true;
    stack<TreeNode*> st;
    TreeNode* current = root;
    // String because there is not a way to know if we have not initialized a var
    string last;
    while(!st.empty() || current){
        while(current){
            // Push all left son nodes
            st.push(current); current = current->left;
        }
        // Get the mostleft son
        current = st.top();
        // Drop it
        st.pop();
        // If it does not exist last or value is greater than last we change our last value
        if(!last.size() || current->val > stoi(last)) last = to_string(current->val);
        else return false;
        // Get the right value
        current = current->right;
    }
    return true;
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
