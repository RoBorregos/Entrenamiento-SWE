/*
Problem: https://leetcode.com/problems/linked-list-cycle/

Approach: Use the fast and slow pointer strategy to detect a cycle.

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

bool hasCycle(ListNode* head) {
    if (!head || !head->next) return false;
    auto conejo = head->next;
    auto tortuga = head;
    while (conejo && conejo->next && tortuga != conejo) {
        tortuga = tortuga->next;
        conejo = conejo->next->next;
    }
    return conejo == tortuga;
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

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3, head->next);

    if (hasCycle(head)) {
        cout << "Has cycle" << endl;
    } else {
        cout << "There's no cycle" << endl;
    }

    deleteList(head);

    return 0;
}
