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
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
struct segtree {
    ll a[1 << 19], arr_size = 1 << 18;
    segtree() {
        memset(a, 0, sizeof(a));
    }
    ll merge(ll a, ll b) {
        return gcd(a, b);
    }
    void update(int index, int value) {
        index += arr_size;
        a[index] = value;
        index >>= 1;
        while(index >= 1) {
            a[index] = merge(a[2 * index], a[2 * index + 1]);
            index >>= 1;
        }
    }
    ll q(int nd, int cur_left, int cur_right, int left, int right) {
        if(cur_left >= left && cur_right <= right) 
            return a[nd];
        else if(cur_left > right || cur_right < left)
            return 0;
        else {
            int mid = (cur_left + cur_right) / 2;
            return merge(q(nd << 1, cur_left, mid, left, right), q((nd << 1) + 1, mid + 1, cur_right, left, right));
        }
    }
    ll query(int left, int right) {
        return q(1, 0, arr_size - 1, left, right);
    }
};
segtree seg;
vector<int> sieve(int limit) {
    bool arr[limit + 1];
    memset(arr, 1, sizeof(arr));
    for(int i = 2; i <= limit; ++i) {
        if(arr[i])
            for(int j = 2 * i; j <= limit; j += i)
                arr[j] = 0;
    }
    vector<int> res;
    for(int i = 2; i <= limit; ++i)
        if(arr[i])
            res.pb(i);
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    /*
    int n, q;
    cin >> n >> q;
    int x[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> x[i], seg.update(i, x[i]);
    for(int i = 0; i < q; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1)
            seg.update(a, b);
        else
            cout << seg.query(a, b) << endl;
    }
    */
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i) {
        seg.update(i, a[i]);
    }
    vector<pair<int, int>> segment;
    for(int i = 1; i <= n; ++i) {
        int l = 1, r = n, tmp;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(seg.query(i, mid) >= mid - i + 1)
                tmp = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        if(seg.query(i, tmp) == tmp - i + 1)
            segment.pb(mp(i, tmp)), i = tmp;
    }
    vector<pair<int, pair<bool, int>>> sweep;
    bool vis[segment.size()];
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < segment.size(); ++i) {
        sweep.pb(mp(segment[i].fi, mp(0, i)));
        sweep.pb(mp(segment[i].se, mp(1, i)));
    }
    set<int> active;
    int res[n + 1], prev = 0;
    memset(res, -1, sizeof(res));
    for(auto i : sweep) {
        bool type = i.se.fi;
        int pos = i.fi;
        int idx = i.se.se;
        if(type) {
            if(active.find(idx) != active.end()) {
                res[pos] = ++prev;
                active.clear();
            }
        }
        else {
            active.ins(idx);
        }
    }
    res[0] = 0;
    for(int i = 1; i <= n; ++i)
        if(res[i] == -1)
            res[i] = res[i - 1];
    for(int i = 1; i <= n; ++i)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}