#include <bits/stdc++.h>
using namespace std;
const int lim = 1e5 + 5;
struct disjoint_set {
    int head[lim], size[lim];
    disjoint_set() {
        memset(head, -1, sizeof(head));
        fill(size, size + lim, 1);
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
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i) 
        cin >> b[i];
    pair<int, int> c[n];
    for(int i = 0; i < n; ++i)
        c[i] = make_pair(a[i], b[i]);
    sort(c, c + n);
    disjoint_set dsu;
    vector<int> d[31];
    for(int i = 0; i < n; ++i) {
        int msb;
        for(int j = 30; j >= 0; --j) {
            if((1 << j) & c[i].first) {
                msb = j;
                break;
            }
        }
        for(int j = msb - 1; j >= 0; --j) {
            if(!((1 << j) & c[i].first) && d[j].size()) {
                for(auto k : d[j])
                    dsu.merge(i, k);
                d[j].clear();
                d[j].push_back(dsu.find_head(i));
            }
        }
        d[msb].push_back(dsu.find_head(i));
    }
    long long res[n];
    memset(res, 0, sizeof(res));
    for(int i = 0; i < n; ++i) {
        res[dsu.find_head(i)] += c[i].second;
    }
    long long out[n];
    set<pair<pair<int, int>, int>> e;
    for(int i = 0; i < n; ++i) {
        e.insert(make_pair(make_pair(a[i], b[i]), i));
    }
    for(int i = 0; i < n; ++i) {
        out[(*e.lower_bound(make_pair(c[i], -100))).second] = res[dsu.find_head(i)];
        e.erase(e.lower_bound(make_pair(c[i], 0)));
    }
    for(int i = 0; i < n; ++i)
        cout << out[i] << endl;
    return 0;
}