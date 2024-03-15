#include <bits/stdc++.h>
using namespace std;
const int lim = 2e5 + 5;
struct disjoint_set {
    // parent/head
    // size
    int size[lim], head[lim];
    disjoint_set() {
        fill(size, size + lim, 1);
        // head 2 pilihan:
        // set to -1
        // set to i
        memset(head, -1, sizeof(head));
    }
    int find_head(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    bool merge(int x, int y) {
        x = find_head(x), y = find_head(y);
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            size[x] += size[y], head[y] = x;
        }
        return x != y;
    }
};
int main() {
    // first -> weight
    // second.first -> node 1
    // second.second -> node 2
    vector<pair<int, pair<int, int>>> edges;
    sort(edges.begin(), edges.end());
    int mst = 0;
    disjoint_set dsu;
    for(auto i : edges) {
        if(dsu.merge(i.second.first, i.second.second))
            mst += i.first;
    }
    cout << mst << endl;
}