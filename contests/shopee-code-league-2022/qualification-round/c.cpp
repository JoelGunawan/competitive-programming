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
    #include <bits/stdc++.h>
    using namespace std;
 
    const int MX = 150005;
 
    struct segtree{
        ll st[MX << 1], arr[MX];
 
        void build(){
            for(int i = MX; i < (MX << 1); i++) st[i] = arr[i - MX];
            for(int i = MX - 1; i > 0; i--) st[i] = max(st[i << 1], st[i << 1|1]);
        }
 
        void update(int p, int value){ // 0-based
            for(st[p += MX] = value, p >>= 1; p >= 1; p >>= 1) st[p] = max(st[p << 1], st[p << 1 | 1]);
        }
 
        ll range(ll l, ll r){ // 0-based [l, r)
            ++r;
            ll res = -1e16;
            for(l += MX, r += MX; l < r; l >>= 1, r >>= 1){
                if(l & 1) res = max(res, st[l++]);
                if(r & 1) res = max(res, st[--r]);
            }
            return res;
        }
    };
    int main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        ll n, m, d;
        cin >> n >> m >> d;
        // a[i] -> location
        // b[i] -> reward
        // t[i] -> time
        // do dynamic programming O(nm)
        // with n is location, m is road
        // transition O(logn) for each state(range query on previous maximum)
        // sort dp by time
        segtree seg[2];
        memset(seg[0].arr, 0, sizeof(seg[0].arr));
        memset(seg[1].arr, 0, sizeof(seg[1].arr));
        // fi -> time, se.fi -> location, se.se -> reward
        pair<int, pair<int, int>> ops[m];
        for(int i = 0; i < m; ++i) {
            int a, b, t;
            cin >> a >> b >> t;
            ops[i] = mp(t, mp(a, b));
        }
        sort(ops, ops + m);
        ll prev_time = -n;
        for(ll i = 0; i < m; ++i) {
            ll a, b, t;
            t = ops[i].fi, a = ops[i].se.fi, b = ops[i].se.se;
            for(ll j = 1; j <= n; ++j) {
                seg[i % 2].arr[j] = seg[(i + 1) % 2].range(max(1ll, j - d * (t - prev_time)), min(n, j + d * (t - prev_time))) + b - abs(j - a);       
                //cout << b - abs(j - a) << " " << seg[i % 2].arr[j] << " " << seg[(i + 1) % 2].range(max(1ll, j - d * (t - prev_time)), min(n, j + d * (t - prev_time))) << endl;
            }
            seg[i % 2].build();
            prev_time = t;
        }
        cout << seg[(m - 1) % 2].range(1, n) << endl;
        return 0;
    }