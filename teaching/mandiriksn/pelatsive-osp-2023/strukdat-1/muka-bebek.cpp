#include <bits/stdc++.h>
using namespace std;
const int lim = 105;
struct disjoint_set {
    int h[lim], sz[lim];
    // constructor 
    // initialize value structnya
    disjoint_set() {
        memset(h, -1, sizeof(h));
        fill(sz, sz + lim, 1);
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
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> v;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            v.push_back(make_pair(x, make_pair(i, j)));
        }
    }
    sort(v.begin(), v.end());
    int res = 0;
    disjoint_set dsu;
    for(auto i : v) {
        if(dsu.merge(i.second.first, i.second.second))
            res += i.first;
    }
    cout << res << endl;
}