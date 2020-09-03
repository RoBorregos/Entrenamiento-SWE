/*
Problem: https://leetcode.com/problems/reverse-linked-list/

Aproach: Reverse a singly linked list.

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


 ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        cout << "Reverse Linked list: ";
        cout << prev->val << "->";
        cout << prev->next->val <<"->";
        cout << prev->next->next->val << "->";
        cout << prev->next->next->next->val << "->";
        cout << prev->next->next->next->next->val << "->";
        cout << prev->next->next->next->next->next;
        return prev;

    }
int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    cout << "Linked list: 1->2->3->4->5->NULL"<< "\n";
    reverseList(head);
    return 0;
}