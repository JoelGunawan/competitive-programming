#!/usr/bin/env python3
import sys
from collections import deque
# from itertools import chain, combinations

def getdegeneracyordering(graph, n, k):
    # O(kn)
    active = [True] * n
    nsize = [len(graph[i]) for i in range(n)]
    
    tinydegs = [[] for i in range(k)]
    tinydegscount = 0
    for i in range(n):
        if nsize[i] < k:
            tinydegs[nsize[i]].append(i)
            tinydegscount += 1

    degorder = [-1] * n
    degorder_i = []
    mindeg = min(nsize)
    while tinydegscount > 0:
        # print(tinydegscount, mindeg, tinydegs)
        while len(tinydegs[mindeg]) == 0:
            mindeg += 1
        node = tinydegs[mindeg].pop()
        if not active[node]: continue
        
        ## This is node to put in ordering!
        degorder[node] = len(degorder_i)
        degorder_i.append(node)
        active[node] = False
        tinydegscount -= 1
        
        # Update state for neighbours
        for nb in graph[node]:
            if not active[nb]: continue
            nsize[nb] -= 1
            if nsize[nb] < k:
                tinydegs[nsize[nb]].append(nb)
                mindeg = min(mindeg, nsize[nb])
                if nsize[nb] == k-1:
                    tinydegscount += 1
                    
    return degorder, degorder_i
    
# def powerset(s):
#     return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))


def getmaxclique(node, graph):
    # returns largest clique of graph (active part) which contains node.
    # O(2^k * k + k^2) (assuming adjecency lists < k)
    rev = {}
    gn = len(graph[node])
    for i, u in enumerate(graph[node]):
        rev[u] = i

    # Make adjacency matrix
    # adjmatrix = [[0] * len(nbhood) for i in range(len(nbhood))]
    bitmasks = [(1<<i) for i in range(len(graph[node]))]
    for i, u in enumerate(graph[node]):
        for v in graph[u]:
            if v in rev:
                bitmasks[i] |= (1<<rev[v])
                bitmasks[rev[v]] |= (1<<i)
                
                # adjmatrix[i][rev[v]] = adjmatrix[rev[v]][i] = 1
        #
    # gn = len(adjmatrix)
    # bitmasks = []
    # for i in range(gn):
    #     adjmatrix[i][i] = 1
    #     bitmasks.append(sum([adjmatrix[i][j]*2**(j) for j in range(gn)]))
    #    
    maxclique = 0
    for subset in range(1, (1<<gn)):
        poscliq = subset
        count = 0
        for i in range(0, gn):
            if (subset >> i) & 1 == 1:
                count += 1
                poscliq &= bitmasks[i]
        if poscliq == subset:
            maxclique = max(maxclique, count)
        #
    # for u in graph[node]:
    #    rev[u] = -1
    # Try all subsets, check if it is a clique.
    # def isclique(myset):
#         for i, u in enumerate(myset):
#             for j in range(i+1, len(myset)):
#                 if adjmatrix[u][myset[j]] == 0:
#                     return False
#         return True
#    
    # maxclique = 0
#     for myset in powerset(list(range(len(nbhood)))):
#         if isclique(myset):
#             maxclique = max(maxclique, len(myset))
#        
    return maxclique + 1
    
def poldev():
    # Step 0: Read input
    n, k = map(int, sys.stdin.readline().split())
    global rev
    graph = []
    for i in range(n):
        graph.append(list(map(int, sys.stdin.readline().split()[1:])))
    
    # Step 1: Find degeneracy order O(kn)
    degorder, degorder_i = getdegeneracyordering(graph, n, k)
    
    # Step 2: Trim graph, such that edges only point forwards in degen. order
    # Adjecency list of each node is now < k
    for node in range(n):
        futureneighs = []
        for nb in graph[node]:
            if degorder[nb] > degorder[node]:
                futureneighs.append(nb)
        assert(len(futureneighs) < k)
        graph[node] = futureneighs
    
    # Step 3: Swipe through in degeneracy ordering: What is largest clique
    # of vertex i, using only future vertices? O(n * 2^k * k^2)
    maxclique = 1
    for node in degorder_i:
        maxclique = max(maxclique, getmaxclique(node, graph))
    
    return maxclique
    
    
print(poldev())