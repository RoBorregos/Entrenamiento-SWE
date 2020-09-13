/*
Problem: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

Approach: Use a queue to serialize the binary tree in a string using Breadth First. 
To deserialize just construct the tree using a queue to make Breadth First Construction.

Time complexity: O(n)

Space complexity: O(n)
*/

#include <climits>
#include <iostream>
#include <queue>
#include <string>

#include "../../Common/BinaryTree.h"

using namespace std;
using namespace SweCommmon;

// Encodes a tree to a single string.
string serialize(TreeNode<int>* root) {
    string serial = "[";
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int> *node = q.front();
        if(node) {
            q.push(node->left);
            q.push(node->right);
        }
        serial += (node? to_string(node->val) : "null") + ',';
        q.pop();
    }
    int i = serial.size()-1;
    while(~i){
        if(serial[i] == 'n') serial.erase(i, 5);
        else if(isdigit(serial[i])) break;
        else i--;
    }
    serial[serial.size()-1] = ']';
    return serial;
}

// return First Value in data string, also erases it.
string getNum(string &data){
    int limit;
    for(int i = 0; i < data.size(); i++){
        if(data[i] == ',' || data[i] == ']'){
            limit = i; break;
        }
    }
    string num = data.substr(0,limit);
    data.erase(0,limit+1);
    return num;
}
    
// Decodes your encoded data to tree.
TreeNode<int>* deserialize(string data) {
    if(data.size()<=2) return nullptr;
    queue<TreeNode<int>*> q;
    data.erase(0,1);
    // Data extraction.
    TreeNode<int>* root = new TreeNode<int>(stoi(getNum(data)));
    q.push(root);
    int sonC = 0;
    while(data.size()){
        // Node set.
        string firstOfData = getNum(data);
        TreeNode<int>* temp = firstOfData=="null"? nullptr : (new TreeNode<int>(stoi(firstOfData)));
        TreeNode<int>* setter = q.front();
        if(!sonC) {
            if(temp) {
                setter->left = temp;
                q.push(setter->left);
            }
            sonC++;
        }
        else {
            if(temp){ 
                setter->right = temp;
                q.push(setter->right);
            }
            sonC = 0;
            q.pop();
        }
    }
    return root;
}

int main() {
    TreeNode<int> *root = new TreeNode<int>(3);
    root->left = new TreeNode<int>(9);
    root->right = new TreeNode<int>(20);
    root->right->left = new TreeNode<int>(15);
    root->right->right = new TreeNode<int>(7);

    string serial = serialize(root);
    cout << serial << endl;
    deleteTree(root);
    root = deserialize(serial);
    printTree(root);
    deleteTree(root);
    return 0;
}
