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
const int lim = 1 << 17;
struct segment_tree {
    int a[2 * lim];
    segment_tree() {
        fill(a, a + 2 * lim, 1e9);
    }
    void update(int idx, int val) {
        idx += lim;
        a[idx] = val;
        while(idx) {
            idx >>= 1;
            a[idx] = min(a[idx << 1] , a[(idx << 1) + 1]);
        }
    }
    int query(int nd, int cl, int cr, int l, int r) {
        if(cl >= l && cr <= r) {
            return a[nd];
        }
        else if(cl > r || cr < l)
            return 1e9;
        else {
            int mid = (cl + cr) / 2;
            return min(query(nd << 1, cl, mid, l, r), query((nd << 1) + 1, mid + 1, cr, l, r));
        }
    }
    int query(int l, int r) {
        return query(1, 0, lim - 1, l, r);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    int a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    // for each L, save minR, query using segment tree
    int q;
    cin >> q;
    // do query based on r
    segment_tree seg;
    vector<pair<pair<int, int>, int>> queries(q);
    for(int i = 0; i < q; ++i)
        cin >> queries[i].fi.se >> queries[i].fi.fi, queries[i].se = i;
    sort(queries.begin(), queries.end());
    int ans[q];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int pref[30][n + 1];
    memset(pref, 0, sizeof(pref));
    for(int i = 1; i <= n; ++i) {
        bool allow_contrib = 1;
        for(int j = 0; j < 30; ++j) {
            if((1 << j) & a[i] && !((1 << j) & x))
                allow_contrib = 0;
        }
        for(int j = 0; j < 30; ++j) {
            pref[j][i] = pref[j][i - 1];
            if((1 << j) & a[i] && (1 << j) & x && allow_contrib) 
                ++pref[j][i];
        }
    }
    for(int i = 1; i <= n; ++i) {
        int l = i, r = n, ans = 1e9;
        while(l <= r) {
            int mid = (l + r) / 2;
            bool valid = 1;
            for(int j = 0; j < 30; ++j) {
                if((1 << j) & x && pref[j][mid] - pref[j][i - 1] == 0)
                    valid = 0;
            }
            if(valid) 
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        pq.push(mp(ans, i));
    }
    for(auto p : queries) {
        int l = p.fi.se, r = p.fi.fi, idx = p.se;
        //cout << l << " " << r << endl;
        while(pq.size() && pq.top().fi <= r) {
            seg.update(pq.top().se, pq.top().fi - pq.top().se + 1);
            pq.pop();
        }
        ans[idx] = seg.query(l, r);
        if(ans[idx] > n)
            ans[idx] = -1;
    }
    for(auto i : ans)
        cout << i << endl;
    return 0;
}