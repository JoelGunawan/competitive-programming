#!/usr/bin/env python3
import sys, math
INF = 10000000000000

def combine(m1, m2, target, k):
    # All matrices must have size k x k
    for start in range(k):
        for end in range(k):
            for mid in range(k):
                d = m1[start][mid] + m2[mid][end]
                target[start][end] = min(target[start][end], d)

def toll():
    # Step 0: Read input
    k, n, m, orders = map(int, sys.stdin.readline().split())
    offset = 1
    while offset <= (n/k): offset *= 2
    segmtree = [ [[INF] * k for j in range(k)] for i in range(2 * offset)]
    mingroup = [ i-offset for i in range(2*offset)]
    maxgroup = [ i+1-offset for i in range(2*offset)]
    
    for i in range(m):
        a, b, t = map(int, sys.stdin.readline().split())
        segmtree[offset + (a // k)][a % k][b % k] = t
    
    # Step 1: Build segment tree
    for i in range(offset-1, 0, -1):
        combine(segmtree[i*2], segmtree[i*2+1], segmtree[i], k)
        mingroup[i] = mingroup[i*2]
        maxgroup[i] = maxgroup[i*2+1]
    
    # Step 2: Process queries
    def getgroup(a, b, node):
        # assert(a < b)
        # assert(b <= maxgroup[node])
        # assert(a >= mingroup[node])
        # Base case:
        if mingroup[node] == a and maxgroup[node] == b:
            return segmtree[node]

        lf = node * 2
        rg = node * 2 + 1
        # assert(maxgroup[lf] == mingroup[rg])
        mid = maxgroup[lf]
        
        # Recursive cases:
        # Only overlap on one subtree
        if a >= mid: return getgroup(a, b, rg)
        if b <= mid: return getgroup(a, b, lf)
        
        # Overlap on both sides:
        m1 = getgroup(a, mid, lf)
        m2 = getgroup(mid, b, rg)
        res = [[INF] * k for i in range(k)]
        combine(m1, m2, res, k)
        return res
        
    
    allorders = sys.stdin.readlines()
    for order in allorders:
        a, b = map(int, order.split())
        group_a, group_b = a // k, b // k
        if group_a >= group_b:
            print(-1)
        else:
            matrix = getgroup(group_a, group_b, 1) # 1 is root
            print(matrix[a%k][b%k] if matrix[a%k][b%k] != INF else -1)
    
    return
    
toll()