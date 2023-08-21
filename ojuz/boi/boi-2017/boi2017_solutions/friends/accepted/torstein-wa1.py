#!/usr/bin/env python3
import sys
from itertools import combinations

## This wrong version assumes that the group of each student is 
## contained in his neighbourhood

def friends():
    # Read input
    n, p, q = map(int, sys.stdin.readline().split())
    graph = []
    for i in range(n):
        graph.append(list(map(int, sys.stdin.readline().split()[1:])))
    
    def find_group(student):
        # Return True if a group containing student exists, False otherwise
        # O(2^(p+q-1) * (p+q)^2)
        friends = graph[student]
        if len(friends) <= q:
            return True
        if len(friends) >= p + q:
            return False
            
        for grsize in range(len(friends) - q, p):
            budget = q + grsize - len(friends)  # This acts as "new" q
            for group in combinations(friends, grsize):
                outside = 0
                for member in group:
                    if len(graph[member]) > grsize + budget:
                        outside = budget+1
                        break
                    for guy in graph[member]:
                        if guy != student and guy not in group:
                            outside += 1
                if outside <= budget:
                    return True
        return False
    
    # If there exists a group for each student, then there say true
    # If for some student it is not possible to find a group, say false
    for i in range(n):
        if not find_group(i):
            return "detention"
            
    return "home"
    
print(friends())