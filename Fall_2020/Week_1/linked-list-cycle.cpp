/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) return false;
        ListNode* conejo = head->next;
        ListNode* tortuga = head;
        while (conejo && conejo->next && tortuga != conejo) {
            tortuga = tortuga->next;
            conejo = conejo->next->next;
        }
        return conejo == tortuga;
    }
};