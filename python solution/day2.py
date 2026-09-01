
#python solution for no. of islands
from collections import deque


def noOfIslands(graph):

    if not graph:
        return -1

    row = len(graph)
    column = len(graph[0])
    count = 0



    def dfs(graph, r, c):

        if r>=row or r<0 or c>=column or c<0 or graph[r][c] == 0:
            return

        graph[r][c] = 0

        dfs(graph, r+1, c)
        dfs(graph, r-1, c)
        dfs(graph, r, c+1)
        dfs(graph, r, c-1)


    for r in range(row):
        for c in range(column):
            if graph[r][c] == 1:
                count+=1
                dfs(graph, r,c)

    return count
                


def preorder(root):
    if root is None:
        return []

    root_val = [root.val]
    left_val = []
    right_val = []

    if root.left:
        left_val = preorder(root.left)

    if root.right:
        right_val = preorder(root.right)

    result = root_val + left_val + right_val

    return result


def binarySearchTree(root, min_val=float('-inf'), max_val=float('inf')):

    if root is None:
        return True

    if root.val <=min_val or root.val >= max_val:
        return False

  
    leftValidation = binarySearchTree(root.left, min_val, root.val)
    rightValidation = binarySearchTree(root.right, root.val, max_val)

    return leftValidation and rightValidation


def lowestCommonAncestor(root, p, q):

    result = root.val

    if p<root.val and q<root.val: 
        result = lowestCommonAncestor(root.left, p, q)

    if p>root.val and q>root.val:
        result = lowestCommonAncestor(root.right, p, q)

    return result


def levelOrder(root):

    if root is None:
        return []

    result = []
    queue = deque([root])

    while queue:

        node = queue.popleft()

        result.append(node.val)

        if node.left:
            queue.append(node.left)

        if node.right:
            queue.append(node.right)

    return result

    


    