/*
Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

Aproach: Given a sorted linked list, delete all duplicates such that each element appear only once.
To solve this you need to create other linked list that its equal to header. Get into a while until
node finish the linket list, and compare actual val whit next and if it is true become actual in
next next if is not just get in the next node.

Time complexity: O(n)
Space complexity: O(n)

*/

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void printLinkedList(ListNode* head) {
    while (head) {
        std::cout << head->val << "->";
        head = head->next;
        if (!head) {
            std::cout << "NULL";
        }
    }
    std::cout << "\n";
}
void deleteList(ListNode* head) {
    while (head != nullptr) {
        auto temp = head->next;
        delete head;
        head = temp;
    }
}

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* node = NULL;
    node = head;
    while (node && node->next) {
        if (node->val == node->next->val) {
            node->next = node->next->next;
        } else {
            node = node->next;
        }
    }
    return head;
}
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);

    std::cout << "Linked list: ";
    printLinkedList(head);

    head = deleteDuplicates(head);

    std::cout << "Edit List: ";
    printLinkedList(head);

    deleteList(head);
    return 0;
}
