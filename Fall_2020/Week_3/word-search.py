'''
Problem: https://leetcode.com/problems/word-search/

Approach: Iteratively traverse de matrix while recording visited coordinates
            for each possible path. 
            
Time complexity: O(n^2)

Space complexity: O(n)
'''

def exist(board, word):
    
    def helper(row, column, index, visited = []):
        visited.append((row, column))
        index += 1
        if index == size:
            if board[row][column] == word[index-1]:
                return True
            else:
                return False    

        right = False
        if row+1 < rows:
            if board[row+1][column] == word[index] and (row+1,column) not in visited:
                right = helper(row+1, column, index, visited.copy())
                if right:
                    return right
                
        left = False  
        if row-1 >= 0:
            if board[row-1][column] == word[index] and (row-1,column) not in visited:
                left = helper(row-1, column, index, visited.copy())
                if left:
                    return left

        down = False
        if column+1 < columns:
            if board[row][column+1] == word[index] and (row,column+1) not in visited:
                down = helper(row, column+1, index, visited.copy())
                if down:
                    return down

        up = False
        if column-1 >= 0:
            if board[row][column-1] == word[index] and (row,column-1) not in visited:
                up = helper(row, column-1, index, visited.copy())
                if up:
                    return up

        return max(right,left,down,up)
    
    size = len(word)
    rows = len(board)
    columns = len(board[0])
    for row in range(rows):
        for column in range(columns):
            if board[row][column] == word[0]:
                if size == 1:
                    return True
                v = []
                if helper(row, column, 0, v):
                    return True
    return False



board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
word = "ABCCED"

if exist(board, word):
    test = ' exists'
else:
    test = ' does not exist'

print(word + test + ' in board.')
