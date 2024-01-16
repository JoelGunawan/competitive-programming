// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
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
const int lim = 1 << 18;
struct lazy_segment_tree {
    long long a[2 * lim], lazy[2 * lim], m_lazy[2 * lim], m[2 * lim], inf = 1e18;
    lazy_segment_tree() {
        memset(a, 0, sizeof(a));
        memset(lazy, 0, sizeof(lazy));
        memset(m_lazy, 0, sizeof(m_lazy));
        memset(m, 0, sizeof(m));
    }
    int arr_size = lim;
    void propagate(int nd, int cl, int cr) {
        m[nd] = min(m[nd], a[nd] + m_lazy[nd]);
        a[nd] += lazy[nd];
        if(cl != cr) {
            m_lazy[2 * nd] = min(m_lazy[2 * nd], lazy[2 * nd] + m_lazy[nd]);
            lazy[2 * nd] += lazy[nd];
            m_lazy[2 * nd + 1] = min(m_lazy[2 * nd + 1], lazy[2 * nd + 1] + m_lazy[nd]);
            lazy[2 * nd + 1] += lazy[nd];
        }
        lazy[nd] = 0;
        m_lazy[nd] = 0;
    }
    void update(int l, int r, long long val) {
        update(1, 0, arr_size - 1, l, r, val);
    }
    void update(int nd, int cl, int cr, int l, int r, long long val) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            m_lazy[nd] = min(m_lazy[nd], lazy[nd] + val);
            lazy[nd] += val;
            propagate(nd, cl, cr);
        }
        else if(cl > r || cr < l) {
            return;
        }
        else {
            int mid = (cl + cr) / 2;
            update(2 * nd, cl, mid, l, r, val);
            update(2 * nd + 1, mid + 1, cr, l, r, val);
        }
    }
};
int main() {
    // do lazy segment tree with special case
    // find minimum throughout all queries
    // if query is addition -> just add to a value, don't change minimum
    // if query is not addition - > check whether it makes it below the previous minimum, change a value

    // start -> reset minimum to cur
    // end -> query minimum
    lazy_segment_tree seg;
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        seg.update(i, i, x);
    }
    while(q--) {
        char query;
        cin >> query;
        if(query == 'C') {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            seg.update(l, r, x);
            /*
            for(int i = 1; i <= n; ++i)
                seg.update(i, i, 0);
            for(int i = 1; i <= n; ++i)
                printf("%lld ", seg.a[i + seg.arr_size]);
            printf("\n");
            for(int i = 1; i <= n; ++i)
                printf("%lld ", seg.m[i + seg.arr_size]);
            printf("\n");
            */
        }
        else if(query == 'I') {
            int i;
            scanf("%d", &i);
            seg.update(i, i, 0);
            seg.m[i + seg.arr_size] = seg.a[i + seg.arr_size];
        }
        else {
            int i;
            scanf("%d", &i);
            seg.update(i, i, 0);
            printf("%lld\n", seg.m[i + seg.arr_size]);
        }
    }
    return 0;
}