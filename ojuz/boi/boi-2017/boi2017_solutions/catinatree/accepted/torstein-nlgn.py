#!/usr/bin/env python3
import sys, math
INF = 100000000

def catinatree():
    # Read input
    n, d = map(int, sys.stdin.readline().split())
    children = [[] for i in range(n)]
    for i in range(1, n):
        children[int(sys.stdin.readline().strip())].append(i)
    
    # Keep state for each node in tree - traverse bottom up,
    # start at the leaves. For each node, remember:
    # - max # of marked nodes in subtree rooted at node
    # - maximum distance to any node in max size set of marked nodes
    maxinsubtree = [-1]*n
    maxdistsubtr = [-1]*n
    
    # Stack-based DFS
    seen = [False] * n
    stack = [0]
    while len(stack) > 0:
        node = stack[-1]
        if not seen[node]:
            seen[node] = True
            for child in children[node]:
                stack.append(child)
        else:
            # At post-processing in DFS tree; all children are processed
            node = stack.pop()
            
            # Base case: a leaf
            if len(children[node]) == 0:
                maxinsubtree[node] = 1
                maxdistsubtr[node] = 0
            
            # Recursive case: internal node of tree
            else:
                # Greedily pick marked nodes from trees where
                # they (the marked nodes) are the furthest away.
                # When it is not possible, drop at most one
                # in those subtrees.
                children[node].sort(key=lambda x: -maxdistsubtr[x])
                furthest = INF
                marked = 0
                for child in children[node]:
                    if furthest + maxdistsubtr[child] + 2 >= d:
                        marked += maxinsubtree[child]
                        furthest = maxdistsubtr[child]
                    else:
                        marked += maxinsubtree[child] - 1
                # If the furthest marked node is sufficiently far away,
                # add yourself to the marked set.
                if furthest + 1 == d:
                    furthest = -1
                    marked += 1
                maxinsubtree[node] = marked
                maxdistsubtr[node] = furthest + 1
    
    return maxinsubtree[0]
    
print(catinatree())