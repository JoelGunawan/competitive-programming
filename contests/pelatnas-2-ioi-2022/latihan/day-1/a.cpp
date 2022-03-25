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
/*struct node {
    int l = -1, r = -1;
    int val = 0;
};
struct segtree {
    vector<node> a;
    vector<int> head;
    int arr_size = 1 << 30;
    void update(int nd, int prev, int cl, int cr, int idx, int val) {
        int mid = (cl + cr) / 2;
        if(prev != -1)
            a[nd] = a[prev];
        a[nd].val += val;
        if(cl == cr) 
            return;
        else if(idx <= mid) {
            if(prev != -1)
                a[nd].r = a[prev].r;
            a[nd].l = a.size(), a.pb(node());
            update(a[nd].l, prev == -1 ? -1 : a[prev].l, cl, mid, idx, val);
        }
        else {
            if(prev != -1)
                a[nd].l = a[prev].l;
            a[nd].r = a.size(), a.pb(node());
            update(a[nd].r, prev == -1 ? -1 : a[prev].r, mid + 1, cr, idx, val);
        }
    }  
    void upd(int idx, int val) {
        head.pb(a.size());
        a.pb(node());
        update(a.size() - 1, head.size() == 1 ? -1 : head[head.size() - 2], 0, arr_size - 1, idx, val);
    }
    // like normal query but use nodes instead
    int query(int nd, int cl, int cr, int l, int r) {
        if(nd == -1 || cl > r || cr < l)
            return 0;
        else if(cl >= l && cr <= r)
            return a[nd].val;
        else {
            int mid = (cl + cr) / 2;
            return query(a[nd].l, cl, mid, l, r) + query(a[nd].r, mid + 1, cr, l, r);
        }
    }
    int q(int op, int l, int r) {
        if(l > r)
            return 0;
        if(op == 0)
            return 0;
        else
            return query(head[op - 1], 0, arr_size - 1, l, r);
    }
};
*/
struct bit {
    int a[300005];
    ll arr_size = 300005;
    void update(int idx, int val) {
        while(idx < arr_size)
            a[idx] += val, idx += (idx&-idx);
    }
    ll query(int idx) {
        int res = 0;
        while(idx > 0)
            res += a[idx], idx -= (idx&-idx);
        return res;
    }
    ll q(int l, int r) {
        if(l > r)
            return 0;
        return query(r) - query(l - 1);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // do a persistent segment tree
    // do 2 sweeps
    // first for bsta of optimal b values in certain indices
    // second is calculating the count of inversions
    // and do a final normal bit sweep line on the a array to count inversion
    int n, m;
    cin >> n >> m;
    ll a[n], b, c[n + 1];
    map<int, bool> vis;
    map<int, int> mapping;
    for(int i = 0; i < n; ++i)
        cin >> a[i], c[i] = a[i];
    cin >> b;
    c[n] = b;
    sort(c, c + n + 1);
    bit prefix, suffix;
    int cur = 1;
    for(int i = 0; i <= n; ++i) {
        if(vis[c[i]])
            c[i] = mapping[c[i]];
        else {
            vis[c[i]] = 1;
            mapping[c[i]] = cur++;
            c[i] = mapping[c[i]];
        }
    }
    for(int i = 0; i < n; ++i)
        a[i] = mapping[a[i]];
    b = mapping[b];
    for(int i = 0; i < n; ++i)
        suffix.update(a[i], 1);
    ll res = INT_MAX;
    ll ans = 0;
    for(int i = 0; i <= n; ++i) {
        res = min(res, prefix.q(b + 1, 300000) + suffix.q(1, b - 1));
        //cout << prefix.q(b + 1, 1e9) << " " << suffix.q(1, b - 1) << endl;
        if(i != n) {
            ans += prefix.q(a[i] + 1, 300000);
            prefix.update(a[i], 1);
            suffix.update(a[i], -1);
        }
    }
    cout << ans + res << endl;
    /*
    segtree prefix, suffix;
    int a[n + 1], b[m + 2];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int j = 1; j <= m; ++j)
        cin >> b[j];
    b[m + 1] = 1e9;
    //cout << 0 << endl, exit(0);
    for(int i = 1; i <= n; ++i) {
        prefix.upd(a[i], 1);
    }
    for(int i = n; i >= 1; --i) {
        suffix.upd(a[i], 1);
    }
    ll res = INT_MAX;
    for(int i = 0; i <= n; ++i) {
        res = min(res, (ll)prefix.q(i, b[0] + 1, 1e9) + suffix.q(n - i, 1, b[0] - 1));
    }
    for(int i = 1; i <= n; ++i) {
        //cout << a[i] << " " << prefix.q(i - 1, a[i] + 1, 1e9) << endl;
        res += prefix.q(i - 1, a[i] + 1, 1e9); 
    }
    cout << res << endl;
    return 0;
    int idx = 1;
    sort(b + 1, b + m + 2);
    vector<int> prev = {b[1]};
    vector<int> ans;
    for(int i = 1; i <= n; ++i) {
        // find first index where it is less than previous
        // use sweep line
        // since it cannot decrease
        int cur = idx;
        while(idx <= m && prefix.q(i, b[idx] + 1, 1e9) + suffix.q(n - i, 1, b[idx] - 1) > prefix.q(i - 1, b[idx] + 1, 1e9) + suffix.q(n - (i - 1), 1, b[idx] - 1)) {
            ++idx;
        }
        // current itu rangenya dari idx ke inf
        //cout << b[idx] << " ";
        prev.pb(b[idx]);
    }
    //cout << endl;
    // choose --upper_bound index
    // that is always most optimal?
    //ll res = 0;
    for(int i = 1; i <= m; ++i) {
        int idx = upper_bound(prev.begin(), prev.end(), *lower_bound(prev.begin(), prev.end(), b[i])) - prev.begin() - 1;
        if(idx == n + 1)
            idx = n;
        //cout << b[i] << " " << idx << endl;
        res += prefix.q(idx, b[i] + 1, 1e9) + suffix.q(n - idx, 1, b[i] - 1);
    }
    //cout << res << endl;
    // do normal for last
    //cout << endl;
    cout << res << endl;
    return 0;
    */
}