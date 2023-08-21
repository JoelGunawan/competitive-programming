#!/usr/bin/env python3
import sys
MOD = int(1e9) + 7 

def plusminus():
    n, m, k = map(int, sys.stdin.readline().split())
    row, col = {}, {}
    forced = []
    for i in range(k):
        line = sys.stdin.readline().split()
        sign, x, y = 1 if line[0] == "+" else -1, int(line[1])-1, int(line[2])-1
        forced.append((sign, x, y))
        
    # Two cases: either first row determine all rows, or first column
    # determine all columns; in case of both, there are two cases.
    
    # Case 1: how many ways if first row determines?
    rowscount = 1
    for sign, x, y in forced:
        rowforce = sign if y % 2 == 0 else -sign
        if x in row and row[x] == -rowforce:
            rowscount = 0
            break
        else:
            row[x] = rowforce
    
    freerows = n - len(row)
    rowscount *= pow(2, freerows, MOD)
    
    # Case 2: how many ways if first col determines?
    colscount = 1
    for sign, x, y in forced:
        colforce = sign if x % 2 == 0 else -sign
        if y in col and col[y] == -colforce:
            colscount = 0
            break
        else:
            col[y] = colforce
            
    freecols = m - len(col)
    colscount *= pow(2, freecols, MOD)
            
    # Case 3: how many ways if both rows and cols are determining?
    bothcount = 0
    if k == 0:
        bothcount = 2
    else:
        alleven = True
        allodd = True
        for sign, x, y in forced:
            sgn = max(0, sign)
            if (sgn + x + y) % 2 == 1:
                alleven = False
            else:
                allodd = False
        if alleven or allodd:
            bothcount = 1
        
    return (rowscount + colscount - bothcount) % MOD
        
    
print(plusminus())