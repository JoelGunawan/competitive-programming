// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
const int lim = 1e3 + 1;
multiset<int> sizes;
struct dsu {
    int head[lim], size[lim];
    dsu() {
        memset(head, -1, sizeof(head));
        fill(size, size + lim, 1);
    }
    int find_head(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    bool merge(int a, int b) {
        int x = find_head(a), y = find_head(b);
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            sizes.erase(sizes.find(size[y]));
            sizes.erase(sizes.find(size[x]));
            head[y] = x, size[x] += size[y];
            //cout << "INSERT " << size[x] << endl;    
            sizes.ins(size[x]);
        }
        return x != y;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, d;
    cin >> n >> d;
    pair<int, int> points[d];
    for(int i = 0; i < d; ++i) {
        cin >> points[i].fi >> points[i].se;
    }
    dsu dsu;
    for(int i = 1; i <= n; ++i)
        sizes.ins(1);
    int over = 0;
    for(int i = 0; i < d; ++i) {
        if(!dsu.merge(points[i].fi, points[i].se))
            ++over;
        auto it = sizes.end();
        int cnt = 0, res = 0;
        while(cnt <= over) {
            ++cnt;
            --it;
            //cout << *it << " ";
            res += *it;
        }
        //cout << endl;
        cout << res - 1 << endl;
    }
    return 0;
}