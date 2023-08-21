#!/usr/bin/env python2
import sys
from collections import deque

def railway():
    # Step 0: Read input O(n)
    n, m, k = map(int, sys.stdin.readline().split())
    graph = [[] for i in range(n)]
    for i in range(1, n):
        a, b = [int(x) - 1 for x in sys.stdin.readline().split()]
        graph[a].append((b, i))
        graph[b].append((a, i))
        
    ministers = []
    for i in range(m):
        ministers.append([int(x) - 1 for x in sys.stdin.readline().split()[1:]])
    
    # print("Graph       ", graph)
    # print("Ministers   ", ministers)
    
    # Step 1: Root the tree at 0, find parent, pre- and post-values (DFS) - O(n)
    root = 0
    stack = deque()
    pre = [-1]*n
    post = [-1]*n
    par = [(-1, -1)]*n
    stack.append((root, -1, -1))
    counter = 0
    while len(stack) > 0:
        node, parent, paredge = stack.pop()
        if pre[node] < 0:
            stack.append((node, parent, paredge))
            pre[node] = counter
            par[node] = (parent, paredge)
            counter += 1
            for nb, ed in graph[node]:
                if pre[nb] < 0:
                    stack.append((nb, node, ed))
        elif post[node] < 0:
            post[node] = counter
            counter += 1
            
    # print("Pre         ", pre)
    # print("Post        ", post)
    # print("Parent      ", par)
            
    # Step 2: For each minister, find set of no-descendants (leaf) cities,
    # using pre- and post-values. At these cities, mark the tree with +1.
    # Simulatenously, mark the tree nodes with which minsters have their
    # leftmost city at this node (nextfindlca). This is O(S log S),
    # can be optimized to O(n) if using one stack per minister + DFS
    treemarks = [0] * n
    nextfindlca = [[] for i in range(n)]  # mark nextfindlca nodes with minsters
    leftmost = [-1] * m
    rightmost = [-1] * m  # remember righmost point for each minister
    for minister in range(m):
        cities = ministers[minister]
        cities.sort(key=lambda x: post[x])
        nextfindlca[cities[0]].append(minister)
        leftmost[minister] = cities[0]
        rightmost[minister] = cities[-1]
        
        nodescendants = deque()
        treemarks[cities[0]] += 1
        prevnondesc = cities[0]
        for node in cities[1:]:
            if pre[node] > post[prevnondesc]:
                nodescendants.append(node)
                treemarks[node] += 1
                prevnondesc = node
        ministers[minister] = nodescendants
    
    # print("Treemarks   ", treemarks)
    # print("Nextfindlca ", nextfindlca)
    # print("Rightmost   ", rightmost)
    
    # Step 3: New DFS to simultaneously find the least common ancestors
    # for every consecutive pair of leaf cities for every minister.
    # When DFS encounter a leftmost unprocessed city for a minister
    # (nextfindlca), binary search the work stack for the least common
    # ancestor for that city and the next.
    # Mark all least common ancestors with -1.
    # Additionally, mark the least common ancestor for the entire minister
    # with an extra -1. O(n + S log n)
    def binsearch(workstack, post, target):
        # Returns item on workstack with smallest post value at least the
        # target. Lb always feasible, ub never feasible.
        lb = 0
        ub = len(workstack)
        while lb + 1 < ub:
            mid = (lb + ub) // 2
            if post[workstack[mid]] >= post[target]:
                # Feasible
                lb = mid
            else:
                ub = mid
        return workstack[lb]
    
    dfsstack = deque()
    dfsstack.append(root)
    workstack = deque()
    seen = [False] * n
    while len(dfsstack) > 0:
        node = dfsstack.pop()
        if not seen[node]:
            seen[node] = True
            dfsstack.append(node)
            workstack.append(node)
            # Binary searches for lca
            for minister in nextfindlca[node]:
                # Entire minister
                if leftmost[minister] == node:
                    right = rightmost[minister]
                    lca = binsearch(workstack, post, right)
                    treemarks[lca] -= 1
                # The next pair for this minister
                if len(ministers[minister]) >= 1:
                    right = ministers[minister].popleft()
                    lca = binsearch(workstack, post, right)
                    treemarks[lca] -= 1
                    nextfindlca[right].append(minister)
                    
            # Contiue DFS
            for nb, ed in graph[node]:
                if not seen[nb]:
                    dfsstack.append(nb)
        else:
            if workstack.pop() != node:
                raise Exception("Logical error with workstack pop")
                
    # Step 4: Bottom up traversal of tree, adding popular edges as encountered
    edges = []
    
    leaves = deque()
    processedkids = [0] * n
    frombelow = [0] * n
    for i in range(1, n):
        if len(graph[i]) == 1:
            leaves.append(i)
    
    while len(leaves) > 0:
        leaf = leaves.pop()
        parent, edge = par[leaf]
        wishes = frombelow[leaf] + treemarks[leaf]
        # print("Leaf:",leaf," frombelow:",frombelow[leaf], " wishes:", wishes)
        if wishes < 0:
            raise Exception("Wishlist is negative - something wrong")
        if wishes >= k:
            edges.append(edge)
        frombelow[parent] += wishes
        processedkids[parent] += 1
        
        if parent != root and processedkids[parent] + 1 == len(graph[parent]):
            leaves.append(parent)
        
    
    
    
    print(len(edges))
    print(" ".join(map(str, sorted(edges))))
    
    return
    
    
railway()
