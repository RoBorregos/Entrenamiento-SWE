'''
Problem: https://leetcode.com/problems/merge-two-binary-trees/

Approach: Recursively traverse both trees while adding the node's value to
            the first tree and expanding it if necessary.
            
Time complexity: O(n)

Space complexity: O(n)
'''

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
def mergeTrees(t1: TreeNode, t2: TreeNode) -> TreeNode:
    if t1 == None:
        return t2
    if t2 == None:
        return t1
    t1.val += t2.val
    def merge(node1, node2):
        if node2 == None:
            return 0
        if node1 == None:
            node1 = node2
        if node1.left != None and node2.left != None and node1 != node2:
            node1.left.val += node2.left.val
        if node1.left == None and node2.left != None:
            node1.left = node2.left
            
        if node1.right != None and node2.right != None and node1 != node2:
            node1.right.val += node2.right.val
        if node1.right == None and node2.right != None:
            node1.right = node2.right
        merge(node1.left, node2.left),merge(node1.right, node2.right)
        return 
    merge(t1, t2)
    return t1



root1 = TreeNode(1)  
root1.left = TreeNode(2)  
root1.right = TreeNode(3)  
root1.left.left = TreeNode(4)  
root1.left.right = TreeNode(5)  
root1.right.right = TreeNode(6) 

root2 = TreeNode(4)  
root2.left = TreeNode(1)  
root2.right = TreeNode(7)  
root2.left.left = TreeNode(3)  
root2.right.left = TreeNode(2)  
root2.right.right = TreeNode(6)  

root = mergeTrees(root1, root2)

def inorder(node): 
    if node == None: 
        return
    inorder(node.left)
    print(node.val, end = " ") 
    inorder(node.right) 
    
inorder(root)
