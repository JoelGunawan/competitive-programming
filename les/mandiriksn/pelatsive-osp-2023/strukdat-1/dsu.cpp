#include <bits/stdc++.h>
using namespace std;
const int lim = 1e5 + 5;
struct disjoint_set {
    int sz[lim], h[lim];
    disjoint_set() {
        fill(sz, sz + lim, 1);
        memset(h, -1, sizeof(h));
    }
    int fh(int nd) {
        return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
    }
    bool merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(sz[x] < sz[y])
                swap(x, y);
            h[y] = x;
            sz[x] += sz[y];
        }
        return x != y;
    }
};
int main() {

}