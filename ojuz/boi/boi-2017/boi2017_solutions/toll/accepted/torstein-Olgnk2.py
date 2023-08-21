#!/usr/bin/env python3
import sys, math
INF = float('inf')

def combine(m1, m2, target, k):
    # All matrices must have size k x k
    for start in range(k):
        for end in range(k):
            for mid in range(k):
                d = m1[start][mid] + m2[mid][end]
                target[start][end] = min(target[start][end], d)
                
# def combine(m1, m2, target, k):
#     for start in range(k):
#         for end in range(k):
#             d = INF
#             for mid in range(k):
#                 d = min(d, m1[(start*k)+(mid%k)] + m2[(mid*k)+(end%k)])
#             target[(start*k)+(end%k)] = d
            
# def combine(a,b):
#     zip_b = list(zip(*b))
#     return [[min(ele_a+ele_b for ele_a, ele_b in zip(row_a, col_b))
#              for col_b in zip_b] for row_a in a]

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
    # def getgroup(a, b, node):
    #     # assert(a < b)
    #     # assert(b <= maxgroup[node])
    #     # assert(a >= mingroup[node])
    #     # Base case:
    #     if mingroup[node] == a and maxgroup[node] == b:
    #         return segmtree[node]
    #
    #     lf = node * 2
    #     rg = node * 2 + 1
    #     # assert(maxgroup[lf] == mingroup[rg])
    #     mid = maxgroup[lf]
    #
    #     # Recursive cases:
    #     # Only overlap on one subtree
    #     if a >= mid: return getgroup(a, b, rg)
    #     if b <= mid: return getgroup(a, b, lf)
    #
    #     # Overlap on both sides:
    #     m1 = getgroup(a, mid, lf)
    #     m2 = getgroup(mid, b, rg)
    #     res = [INF]*(k**2)
    #     combine(m1, m2, res, k)
    #     return res
        
    def getgroup(a, b, ai):
        # if a+1 == b:
#             return segmtree[offset+a]
#    
        a, b = offset+a, offset+b
        leftside = [a]
        rightside = []
        while a//2 != b//2:
            if a%2 == 0:
                leftside.append(a+1)
            a //= 2
            if b%2 == 1:
                rightside.append(b-1)
            b //= 2
            
        nextS = [0]*k
        shortest = [INF]*k
        shortest[ai] = 0
            
        for node in leftside:
            # print("a", shortest)
            for i in range(k):
                nextS[i] = shortest[0] + segmtree[node][0][i]
                for j in range(1, k):
                    nextS[i] = min(nextS[i], shortest[j] + segmtree[node][j][i])
            shortest, nextS = nextS, shortest
            
        for ii in range(len(rightside)-1, -1, -1):
            # print("b", shortest)
            node = rightside[ii]
            for i in range(k):
                nextS[i] = shortest[0] + segmtree[node][0][i]
                for j in range(1, k):
                    nextS[i] = min(nextS[i], shortest[j] + segmtree[node][j][i])
            shortest, nextS = nextS, shortest
            
        # print("c", shortest)
        return shortest
        
    # print('precess')
    
    allorders = sys.stdin.readlines()
    for order in allorders:
        a, b = map(int, order.split())
        group_a, group_b = a // k, b // k
        if group_a >= group_b:
            print(-1)
        else:
            vector = getgroup(group_a, group_b, a%k) # 1 is root
            # print("v", vector)
            print(vector[b%k] if vector[b%k] != INF else -1)
    # print('done')
    return
    
toll()