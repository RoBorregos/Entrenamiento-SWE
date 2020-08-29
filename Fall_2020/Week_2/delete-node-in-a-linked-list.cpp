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

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    bool is_cycle;
    explicit ListNode(int x) : val(x), next(nullptr), is_cycle(false) {}
    ListNode(int x, ListNode* n) : val(x), next(n), is_cycle(true) {}
    ~ListNode() { cout << "deleted node: " << val << endl; }
};

void deleteNode(ListNode* node) {
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

void deleteList(ListNode* head) {
    while (head != nullptr) {
        auto temp = head->next;
        if (head->is_cycle) {
            delete head;
            return;
        } else {
            delete head;
            head = temp;
        }
    }
}

void printList(ListNode* head) {
    auto temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    printList(head);

    deleteNode(head->next);

    printList(head);

    deleteList(head);

    return 0;
}
