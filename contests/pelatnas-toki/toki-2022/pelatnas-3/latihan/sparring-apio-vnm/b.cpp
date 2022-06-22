#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second
#define ll long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int lim = 1 << 17;
int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
// multiplication lazy segment tree
struct segment_tree {
    ll a[2 * lim], lazy[2 * lim], size = lim;
    segment_tree() {
        fill(a, a + 2 * lim, 1);
        fill(lazy, lazy + 2 * lim, 1);
    }
    void propagate(int nd, int cl, int cr) {
        a[nd] = (a[nd] * lazy[nd]) % mod;
        if(cl != cr) {
            lazy[2 * nd] = (lazy[2 * nd] * lazy[nd]) % mod;
            lazy[2 * nd + 1] = (lazy[2 * nd + 1] * lazy[nd]) % mod;
        }
        lazy[nd] = 1;
    }
    void update(int nd, int cl, int cr, int l, int r, int val) {
        propagate(nd, cl, cr);
        if(cl > r || cr < l)
            return;
        else if(cl >= l && cr <= r) {
            lazy[nd] *= val;
            lazy[nd] %= mod;
            propagate(nd, cl, cr);
        }
        else {
            // get sum of L and R
            // since we want sum query
            int mid = (cl + cr) / 2;
            update(2 * nd, cl, mid, l, r, val);
            update(2 * nd + 1, mid + 1, cr, l, r, val);
            a[nd] = (a[2 * nd] + a[2 * nd + 1]) % mod;
        }
        // non lazy update -> set value
    }
    void se_update(int nd, int cl, int cr, int idx, int val) {
        propagate(nd, cl, cr);
        int mid = (cl + cr) / 2;
        if(cl == cr) {
            a[nd] = val;
            return;
        }
        if(idx <= mid)
            se_update(2 * nd, cl, mid, idx, val);
        else
            se_update(2 * nd + 1, mid + 1, cr, idx, val);
        a[nd] = (a[2 * nd] + a[2 * nd + 1]) % mod;
    }
    void se_update(int idx, int val) {
        se_update(1, 0, size - 1, idx, val);
    }
    void update(int l, int r, int val) {
        update(1, 0, size - 1, l, r, val);
    }
    ll query(int nd, int cl, int cr, int l, int r) {
        propagate(nd, cl, cr);
        int mid = (cl + cr) / 2;
        if(cl > r || cr < l)
            return 0;
        else if(cl >= l && cr <= r)
            return a[nd];
        else {
            return (query(2 * nd, cl, mid, l, r) + query(2 * nd + 1, mid + 1, cr, l, r)) % mod;
        }
    }
    ll query(int l, int r) {
        return query(1, 0, size - 1, l, r);
    }
};
ll mulmod(ll a, ll b) {
    return (a * b) % mod;
}
ll submod(ll a, ll b) {
    return (((a - b) % mod) + mod) % mod;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // sort triplets by xj
    // mark indices as taken or not
    int n, m, k;
    cin >> n >> m >> k;
    pair<int, pair<int, int>> queries[m];
    set<int> avail;
    for(int i = 1; i <= n; ++i) {
        avail.insert(i);
    }
    for(int i = 0; i < m; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        queries[i] = {x, {l, r}};
    }
    sort(queries, queries + m);
    ll res = 1;
    int idx = 0;
    segment_tree segtree;
    while(idx < m) {
        int cur = queries[idx].fi;
        vector<pair<int, int>> p;
        while(idx < m && queries[idx].fi == cur) {
            // input l dan r
            p.push_back(queries[idx].se);
            ++idx;
        }
        set<int> nums;
        for(auto i : p) {
            while(avail.lower_bound(i.fi) != avail.end() && *avail.lower_bound(i.fi) <= i.se)
                nums.insert(*avail.lower_bound(i.fi)), avail.erase(avail.lower_bound(i.fi));
        }
        bool ans = 1;
        for(auto i : p) {
            if(nums.lower_bound(i.fi) == nums.upper_bound(i.se))
                ans = 0;
        }
        if(!ans)
            cout << 0 << endl, exit(0);
        vector<int> x;
        for(auto i : nums)
            x.push_back(i);
        // get r and get l
        // for each r, get closest l
        ll dp[nums.size() + 1];
        int maxL[nums.size() + 1];
        memset(maxL, 0, sizeof(maxL));
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        segtree.update(0, 0, 1);
        int last = 0;
        for(auto i : p) {
            maxL[--upper_bound(x.begin(), x.end(), i.se) - x.begin() + 1] = lower_bound(x.begin(), x.end(), i.fi) - x.begin() + 1;
            last = max(last, (int)(lower_bound(x.begin(), x.end(), i.fi) - x.begin()) + 1);
        }
        int curl = 0;
        for(int i = 0; i <= nums.size(); ++i)
            segtree.se_update(i, 1);
        for(int i = 1; i <= nums.size(); ++i) {
            // kali dengan (x - 1) ^ (dist - 1) untuk setiap indeks
            // multiply by cur later
            // cari di indeks ini maxL nilai brp
            // buat dp dari maxL sampai i - 1
            // maxL shift by 1 to the left (pake maxL di indeks i - 1)
            dp[i] = segtree.query(curl, i - 1);
            segtree.update(0, i - 1, cur - 1);
            segtree.se_update(i, dp[i]);
            //cout << dp[i] << " ";
            curl = max(curl, maxL[i]);
        }
        //cout << endl;
        ll tmp_res = 0;
        for(int i = curl; i <= nums.size(); ++i)
            tmp_res += mulmod(dp[i], powmod(cur - 1, nums.size() - i));
        tmp_res %= mod;
        //cout << cur << " " << tmp_res << endl;
        res = mulmod(res, tmp_res);
    }
    res = mulmod(res, powmod(k, avail.size()));
    cout << res << endl;
    return 0;
}