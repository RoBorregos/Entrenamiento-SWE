#ifndef COMMON_LINKEDLIST_H_
#define COMMON_LINKEDLIST_H_

#include <iostream>

namespace SweCommmon {

// ListNode simple structure.
// there's a value "is_cycle" which indicates that the current node
// points to an already referenced node.
template <typename T>
struct ListNode {
    T val;
    ListNode* next;
    bool is_cycle;
    explicit ListNode(T x) : val(x), next(nullptr), is_cycle(false) {}
    ListNode(T x, ListNode* n) : val(x), next(n), is_cycle(true) {}
    ~ListNode() { std::cout << "deleted node: " << val << std::endl; }
};

// Deletes all the list starting from head, until it reaches the end
// or until it finds a loop.
template <typename T>
void deleteList(ListNode<T>* head) {
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

template <typename T>
void printList(ListNode<T>* head) {
    auto temp = head;
    while (temp) {
        std::cout << temp->val << "->";
        if (temp->is_cycle) {
            std::cout << temp->next->val << " CYCLE\n";
            return;
        }
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

}  // namespace SweCommmon

#endif  // COMMON_LINKEDLIST_H_
