/*
Problem: https://leetcode.com/problems/delete-node-in-a-linked-list/

Approach: Since we only have access to the node we want to delete, the strategy is
            to switch the values one to the left, resulting in a "deletion" of the node.
            Finally, the last node of the list needs to be deleted, and the previous to last needs
            to point to nullptr.

Time complexity: O(n)

Space complexity: O(1)
*/

#include <iostream>
#include <vector>
#include "../../Common/LinkedList.h"

using namespace std;
using namespace SweCommmon;

void deleteNode(ListNode<int>* node) {
    auto temp = node;
    auto before = temp;
    while (temp->next != nullptr) {
        temp->val = temp->next->val;
        before = temp;
        temp = temp->next;
    }
    delete before->next;
    before->next = nullptr;
}

int main() {
    ListNode<int>* head = new ListNode<int>(1);
    head->next = new ListNode<int>(2);
    head->next->next = new ListNode<int>(3);

    printList(head);

    deleteNode(head->next);

    printList(head);

    deleteList(head);

    return 0;
}
