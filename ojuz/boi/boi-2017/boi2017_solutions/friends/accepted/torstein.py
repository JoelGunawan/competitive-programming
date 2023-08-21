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
            
    for i in range(n):
        for nb in graph[i]:
            if i not in graph[nb]:
                return "detention"
                
    
    
    def find_group(isin, nbhood, isout, enb, eout, depth=0):
        # Input: set of vertices in, in neighbourhood, out, number of edges
        # in--nbhood, number of edges in--out.
        # Return True if a group containing isin with <= q out-edges exists
        if enb + eout <= q:
            return True, set(isin)
        elif eout > q or len(isin) >= p:
            return False, None
        
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
        

        res, theGroup = find_group(isin, nbhood, isout, newenb, neweout, depth=depth+1)
        
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
            return True, theGroup
        
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
        
        res, theGroup = find_group(isin, nbhood, isout,
                            enb - emove, eout + emove, depth=depth+1)
        
        # Cleanup, case 2
        isout.pop()
        for nb in graph[new]:
            nbsinutset[nb] -= 1
            
        nbhood.append(new)
        
        # temp3 = (tuple(isin), tuple(nbhood), tuple(isout), enb, eout)
        # print("  "*depth, "At end 2", temp3)
        # assert(temp0 == temp3)
        return res, theGroup
        
    
    groups = []
    # If there exists a group for each student, then there say true
    # If for some student it is not possible to find a group, say false
    nbsininset = [0] * n
    nbsinutset = [0] * n
    hasGroup = [False] * n
    for i in range(n):
        if hasGroup[i]: continue
        for nb in graph[i]:
            nbsininset[nb] = 1
            
        isGroup, theGroup = find_group([i], graph[i][:], [], len(graph[i]), 0)
        if not isGroup:
            return "detention"
        groups.append(theGroup)
        for elem in theGroup:
            hasGroup[elem] = True
            
        for nb in graph[i]:
            nbsininset[nb] = 0
            
    # Build partition from sets
    partitioning = [set(groups[0])]
    mygroup = [-1] * n
    for elem in partitioning[0]:
        mygroup[elem] = 0
    
    def countCrEdges(group):
        count = 0
        for node in group:
            for nb in graph[node]:
                if nb not in group:
                    count += 1
        return count
        
    # Merge one by one
    def merge(partition, group):
        realgroup = set(group)
        for elem in group:
            partid = mygroup[elem]
            if partid < 0: continue
            # Merge part with group
            smallPart = set(partition[partid])
            smallGroup = set(realgroup)
            intersect = set()
            for elem in partition[partid]:
                if elem in realgroup:
                    intersect.add(elem)
                    smallPart.remove(elem)
                    smallGroup.remove(elem)
            if countCrEdges(smallPart) <= q:
                for elem in intersect:
                    mygroup[elem] = -1
                partition[partid] = smallPart
            elif countCrEdges(smallGroup) <= q:
                realgroup = smallGroup
        for elem in realgroup:
            mygroup[elem] = len(partition)
        partition.append(realgroup)
        
    for group in groups[1:]:
        merge(partitioning, group)
        
    # Clean partitioning
    final = []
    for part in partitioning:
        if len(part) > 0:
            final.append(part)
            
    def makeString(final):
        res = 'home\n'
        res += str(len(final))
        for part in final:
            res += '\n'
            res += str(len(part))
            for node in part:
                res += " " + str(node)
        return res

    return makeString(final)
    
    
print(friends())