'''
Problem: https://leetcode.com/problems/add-two-numbers/

Approach: Add both linked lists into an integer, then make it a reversed 
            string and create the linked list while traversing it.
            
Time complexity: O(n)

Space complexity: O(n)
'''

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def addTwoNumbers(l1: ListNode, l2: ListNode) -> ListNode:
    val = 0
    for head in (l1,l2):
        count = 0
        while head != None:
            val += head.val*10**count
            count += 1
            head = head.next
    string = str(val)[::-1]
    head = ListNode(string[0])
    start = head
    for i in range(1,len(string)):
        start.next = ListNode(int(string[i]))
        start = start.next
    return head
    
    

a1 = ListNode(2)
a2 = ListNode(4)
a3 = ListNode(3)
a1.next = a2
a2.next = a3

b1 = ListNode(5)
b2 = ListNode(6)
b3 = ListNode(4)
b1.next = b2
b2.next = b3

head = addTwoNumbers(a1, b1)

string = ''
while head != None:
    string += str(head.val) + ' -> '
    head = head.next

print(string[:-4])

