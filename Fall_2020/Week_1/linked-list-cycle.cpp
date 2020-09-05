/*
Problem: https://leetcode.com/problems/linked-list-cycle/

Approach: Use the fast and slow pointer strategy to detect a cycle.

Time complexity: O(n)

Space complexity: O(1)
*/

#include <iostream>
#include <vector>
#include "../../Common/LinkedList.h"

using namespace std;
using namespace SweCommmon;

bool hasCycle(ListNode<int>* head) {
    if (!head || !head->next) return false;
    auto conejo = head->next;
    auto tortuga = head;
    while (conejo && conejo->next && tortuga != conejo) {
        tortuga = tortuga->next;
        conejo = conejo->next->next;
    }
    return conejo == tortuga;
}

void deleteList(ListNode<int>* head) {
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

int main() {
    ListNode<int>* head = new ListNode<int>(1);
    head->next = new ListNode<int>(2);
    head->next->next = new ListNode<int>(3, head->next);

    printList(head);

    if (hasCycle(head)) {
        cout << "Has cycle" << endl;
    } else {
        cout << "There's no cycle" << endl;
    }

    deleteList(head);

    return 0;
}
