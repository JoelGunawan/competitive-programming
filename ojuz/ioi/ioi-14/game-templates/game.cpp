#include "game.h"
#include <bits/stdc++.h>
using namespace std;
const int lim = 1505;
struct disjoint_set {
    int h[lim], sz[lim];
    int cnt[lim][lim];
    disjoint_set() {
        memset(cnt, 0, sizeof(cnt));
        fill(sz, sz + lim, 1);
        memset(h, -1, sizeof(h));
    }
    int fh(int nd) {
        return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
    }
    void merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(sz[x] < sz[y])
                swap(x, y);
            h[y] = x;
            sz[x] += sz[y];
            // tiap cnt yg menuju y diganti menuju x
            for(int i = 0; i <= 1500; ++i)
                cnt[x][i] += cnt[y][i], cnt[i][x] += cnt[i][y];
        }
    }
};
disjoint_set dsu;
void initialize(int n) {
    // if every edge between 1 connected component and another has been visited, then output yes
    // else don't output yes :D
    // antara tiap connected component cek jumlah edge yang sudah terpakai
    // nanti tiap merging connected comoponent, tiap node lain di merging juga
}

int hasEdge(int u, int v) {
    int target = dsu.sz[dsu.fh(u)] * dsu.sz[dsu.fh(v)];
    if(dsu.cnt[dsu.fh(u)][dsu.fh(v)] == target - 1) {
        dsu.merge(u, v);
        return 1;
    }
    else {
        dsu.cnt[dsu.fh(u)][dsu.fh(v)]++;
        dsu.cnt[dsu.fh(v)][dsu.fh(u)]++;
        return 0;
    }
}
