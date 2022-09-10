#include <bits/stdc++.h>
using namespace std;
const int lim = 1e3 + 5;
// isi size dari connected component
multiset<int> s;
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
            // hilangin size[x] di dalam multiset
            // hilangin size[y] di dalam multiset
            // tambahkan size[x] yang sudah digabung dengan size[y] di dalam multiset
            s.erase(set.find(size[x]));
            s.erase(s.find(size[y]));
            s.insert(size[x] + size[y]);
            size[x] += size[y], head[y] = x;
        }
        return x != y;
    }
}
int main() {
    int n, d;
    cin >> n >> d;
    pair<int, int> a[d];
    for(int i = 0; i < d; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    for(int i = 1; i <= n; ++i)
        s.insert(1);
    int over = 0;
    disjoint_set dsu;
    for(int i = 1; i <= d; ++i) {
        if(!dsu.merge(a[i].first, a[i].second))
            ++over;
        auto it = s.end();
        int res = 0;
        for(int j = 0; j <= over; ++j) {
            --it;
            res += *it;
        }
        cout << res - 1 << endl;
    }
}