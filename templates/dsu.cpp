#include <bits/stdc++.h>
using namespace std;
const int lim = 2e5 + 5;
struct dsu {
    int head[lim], size[lim];
    dsu() {
        memset(head, -1, sizeof(head));
        fill(size, size + lim, 1);
    }
    int find_head(int nd) {
        while(head[nd] == -1)
            nd = head[nd];
        return nd;
    }
    bool merge(int x, int y) {
        x = find_head(x), y = find_head(y);
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            size[x] += size[y];
            head[y] = x;
        }
        return x != y;
    }
}