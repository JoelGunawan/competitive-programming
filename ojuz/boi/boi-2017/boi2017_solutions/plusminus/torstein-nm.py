#!/usr/bin/env python3
import sys
MOD = int(1e9) + 7

def plusminus():
    n, m, k = map(int, sys.stdin.readline().split())
    grid = [[0] * m for i in range(n)]
    forced = []
    alleven = True
    allodd = True
    for i in range(k):
        line = sys.stdin.readline().split()
        sign, x, y = 1 if line[0] == "+" else -1, int(line[1])-1, int(line[2])-1
        grid[x][y] = sign
        if (x + y + max(0, sign)) % 2 == 0:
            allodd = False
        else:
            alleven = False
        
    # Two cases: either first row determine all rows, or first column
    # determine all columns; in case of both, there are two cases.
    
    # Case 1: how many ways if first row determines?
    rowscount = 1
    for row in grid:
        force = 0
        for i, elm in enumerate(row):
            if elm != 0:
                newforce = elm if i % 2 == 0 else -elm
                if force == -newforce:
                    rowscount = 0
                    break
                else:
                    force = newforce
        if rowscount == 0:
            break
        if force == 0:
            rowscount = (2 * rowscount) % MOD
    
    # Case 2: how many ways if first col determines?
    colscount = 1
    for i in range(m):
        force = 0
        for j in range(n):
            if grid[j][i] != 0:
                newforce = grid[j][i] if j % 2 == 0 else -grid[j][i]
                if force == -newforce:
                    colscount = 0
                    break
                else:
                    force = newforce
        if colscount == 0:
            break
        if force == 0:
            colscount = (2 * colscount) % MOD
            
    # Case 3: how many ways if both rows and cols are determining?
    bothcount = 0
    bothcount += 1 if alleven else 0
    bothcount += 1 if allodd else 0
    
    return (rowscount + colscount - bothcount) % MOD
        
    
print(plusminus())