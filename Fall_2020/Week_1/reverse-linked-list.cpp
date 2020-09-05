/*
Problem: https://leetcode.com/problems/reverse-linked-list/

Aproach: Reverse a singly linked list by getting 3 variables, next, current and prev
in te cycle you are moving the pointers, current become next, prev become curr and next is
one pointer forward of curr. Also, next pointer of curr become prev, to invert te directions
of the linked list. And you retrun prev, becosuse in the last position curr is null.

Time complexity: O(n)
Space complexity: O(n)

*/

#include <iostream>
#include "../../Common/LinkedList.h"

using namespace std;
using namespace SweCommmon;


ListNode<int>* reverseList(ListNode<int>* head) {
    ListNode<int>* prev = NULL;
    while (head) {
        ListNode<int>* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
int main() {
    ListNode<int>* head = new ListNode<int>(1);
    head->next = new ListNode<int>(2);
    head->next->next = new ListNode<int>(3);
    head->next->next->next = new ListNode<int>(4);
    head->next->next->next->next = new ListNode<int>(5);

    cout << "Linked list: ";
    printList(head);

    head = reverseList(head);

    cout << "Reverse Linked List: ";
    printList(head);

    deleteList(head);
    return 0;
}
