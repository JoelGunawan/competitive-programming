#!/usr/bin/env python3
import sys

def friends():
    # Read input
    n, p, q = map(int, sys.stdin.readline().split())
    graph = []
    for i in range(n):
        graph.append(list(map(int, sys.stdin.readline().split()[1:])))
        if len(graph[-1]) >= p+q:
            return "detention"
    
    def find_group(isin, nbhood, isout, enb, eout, depth=0):
        # Input: set of vertices in, in neighbourhood, out, number of edges
        # in--nbhood, number of edges in--out.
        # Return True if a group containing isin with <= q out-edges exists
        if enb + eout <= q:
            return True
        elif eout > q or len(isin) >= p:
            return False
        
        # temp0 = (tuple(isin), tuple(nbhood), tuple(isout), enb, eout)
        # print("  "*depth, "Enter  ", temp0)
        new = nbhood.pop() # Should always be possible, else logic error
        
        # temp1 = (tuple(isin), tuple(nbhood), tuple(isout), enb, eout)
        # print("  "*depth, "Examine", temp1, new)
        
        # Case 1: Goes to group
        isin.append(new)
        neweout = eout
        newenb = enb
        addednbhood = 0
        for nb in graph[new]:
            nbsininset[nb] += 1
            if nb in isout:
                neweout += 1
            elif nb in isin:
                newenb -= 1
            elif nb in nbhood:
                newenb += 1
            else:
                newenb += 1
                addednbhood += 1
                nbhood.append(nb)
        

        res = find_group(isin, nbhood, isout, newenb, neweout, depth=depth+1)
        
        # Cleanup of case 1
        isin.pop()
        for i in range(addednbhood):
            nbhood.pop()
        for nb in graph[new]:
            nbsininset[nb] -= 1
            
        if res:
            nbhood.append(new)
            # temp3 = (tuple(isin), tuple(nbhood), tuple(isout), enb, eout)
            # print("  "*depth, "At end 1", temp3)
            # assert(temp0 == temp3)
            return True
        
        # temp2 = (tuple(isin), tuple(nbhood), tuple(isout), enb, eout)
        # print("  "*depth, "Midway ", temp2)
        # assert(temp1 == temp2)
        # Case 2: Goes out of group
        isout.append(new)
        emove = 0
        for nb in graph[new]:
            nbsinutset[nb] += 1
            if nb in isin:
                emove += 1
        
        res = find_group(isin, nbhood, isout,
                            enb - emove, eout + emove, depth=depth+1)
        
        # Cleanup, case 2
        isout.pop()
        for nb in graph[new]:
            nbsinutset[nb] -= 1
            
        nbhood.append(new)
        
        # temp3 = (tuple(isin), tuple(nbhood), tuple(isout), enb, eout)
        # print("  "*depth, "At end 2", temp3)
        # assert(temp0 == temp3)
        return res
        
    
    # If there exists a group for each student, then there say true
    # If for some student it is not possible to find a group, say false
    nbsininset = [0] * n
    nbsinutset = [0] * n
    for i in range(n):
        for nb in graph[i]:
            nbsininset[nb] = 1
        if not find_group([i], graph[i][:], [], len(graph[i]), 0):
            return "detention"
        for nb in graph[i]:
            nbsininset[nb] = 0
            
    return "home"
    
print(friends())