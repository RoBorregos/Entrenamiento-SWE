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
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

void printLinkedList(ListNode*head){
    while(head){
        cout << head->val << "->";
        head = head->next;
        if (!head){
            cout << "NULL";
        }
    }
    cout << "\n";

}

void deleteList(ListNode* head) {
    while (head != nullptr) {
        auto temp = head->next;
        delete head;
        head = temp;
    }
       
}
 ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;

    }
int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Linked list: ";
    printLinkedList(head);

    head = reverseList(head);

    cout<< "Reverse Linked List: ";
    printLinkedList(head);

    deleteList(head);
    return 0;
}