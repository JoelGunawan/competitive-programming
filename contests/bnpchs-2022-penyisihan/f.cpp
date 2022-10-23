// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
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
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll lim = 2e5 + 5;
struct fenwick {
    ll a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void update(ll idx, ll val) {
        assert(idx != 0);
        while(idx < lim) {
            a[idx] += val;
            idx += idx&-idx;
            assert(idx != 0);
        }
    }
    ll query(ll l, ll r) {
        return query(r) - query(l - 1);
    }
    ll query(ll idx) { 
        ll res = 0;
        while(idx) {
            res += a[idx];
            idx -= idx&-idx;
        }
        return res;
    }
};
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
    long long n, q;
    cin >> n >> q;
    // make map<ll, v<ll>>
    // binser on that map
    // find how many in a row
    long long a[n + 5];
    memset(a, 0, sizeof(a));
    for(ll i = 1; i <= n; ++i)
        cin >> a[i];
    pair<ll, pair<ll, ll>> queries[q + 1];
    for(ll i = 1; i <= q; ++i) {
        long long t;
        cin >> t;
        if(t == 1) {
            long long idx, x;
            cin >> idx >> x;
            queries[i] = mp(t, mp(idx, x));
        }
        else {
            long long k;
            cin >> k;
            queries[i] = mp(t, mp(k, 0));
        }
    }
    // get all x/a[i] values and compres
    map<ll, ll> compress, inv, rev;
    for(ll i = 1; i <= n; ++i) {
        ++compress[a[i]];
    }
    for(ll i = 1; i <= q; ++i) {
        if(queries[i].fi == 1)
            ++compress[queries[i].se.se];
    }
    ll tmp = 0;
    for(auto i : compress) {
        inv[i.fi] = ++tmp;
    }
    for(auto i : inv) {
        rev[i.se] = i.fi;
    }
    for(ll i = 1; i <= n; ++i)
        a[i] = inv[a[i]];
    for(ll i = 1; i <= q; ++i) {
        if(queries[i].fi == 1)
            queries[i].se.se = inv[queries[i].se.se];
    }
    ordered_set s[200005];
    fenwick cnt, mul;
    for(ll i = 1; i <= n; ++i) {
        s[a[i]].insert(i);
        ll l = 0, r = s[a[i]].order_of_key(i), ans, tmp = r;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if(i - *s[a[i]].find_by_order(mid) == tmp - mid) {
                r = mid - 1;
                ans = mid;
            }
            else
                l = mid + 1;
        }
        if(ans != tmp) {
            tmp = tmp - ans + 1;
            cnt.update(tmp - 1, -1 * rev[a[i]]), cnt.update(tmp, 1 * rev[a[i]]);
            mul.update(tmp - 1, -(tmp - 1) * rev[a[i]]), mul.update(tmp, tmp * rev[a[i]]);
        }
        else   
            cnt.update(1, rev[a[i]]), mul.update(1, rev[a[i]]);
    }
    //cout << "TEST" << endl;
    for(ll i = 1; i <= q; ++i) {
        if(queries[i].fi == 1) {
            ll idx = queries[i].se.fi, val = queries[i].se.se;
            if(a[idx] == val)
                continue;
            s[val].insert(idx);
            //cout << a[idx] << " " << a[idx - 1] << " " << a[idx + 1] << endl;
            if(a[idx] == a[idx - 1] && a[idx] == a[idx + 1]) {
                ll ref = s[a[idx]].order_of_key(idx);
                ll l = ref, r = s[a[idx]].size() - 1, lans, rans;
                //cout << l << " " << r << endl;
                while(l <= r) {
                    ll mid = (l + r) >> 1;
                    //cout << mid << endl;
                    //cout << ref << " " << *s[a[idx]].find_by_order(mid) << " " << idx << " " << mid << endl;
                    if(idx - (ll)*s[a[idx]].find_by_order(mid) == ref - mid) {
                        //cout << "GOT " << mid << endl;
                        l = mid + 1;
                        rans = mid;
                    }
                    else
                        r = mid - 1;
                }
                l = 0, r = ref;
                while(l <= r) {
                    ll mid = (l + r) >> 1;
                    if(idx - (ll)*s[a[idx]].find_by_order(mid) == ref - mid) {
                        r = mid - 1;
                        lans = mid;
                    }
                    else
                        l = mid + 1;
                }
                //cout << lans << " " << rans << " " << ref << endl;
                ll ls = ref - lans, rs = rans - ref;
                //cout << ls << " " << rs << endl;
                cnt.update(ls, 1 * rev[a[idx]]), cnt.update(rs, 1 * rev[a[idx]]), cnt.update(ls + rs + 1, -1 * rev[a[idx]]), cnt.update(1, 1 * rev[val]);
                mul.update(ls, ls * rev[a[idx]]), mul.update(rs, rs * rev[a[idx]]), mul.update(ls + rs + 1, -(ls + rs + 1) * rev[a[idx]]), mul.update(1, 1 * rev[val]);
            }
            else if(a[idx] == a[idx - 1]) {
                ll l = 0, ref = s[a[idx]].order_of_key(idx), r = ref, ans;
                while(l <= r) {
                    ll mid = (l + r) >> 1;
                    if(idx - *s[a[idx]].find_by_order(mid) == ref - mid) {
                        r = mid - 1;
                        ans = mid;
                    }
                    else
                        l = mid + 1;
                }
                ll sz = ref - ans + 1;
                cnt.update(sz, -1 * rev[a[idx]]), cnt.update(sz - 1, 1 * rev[a[idx]]);
                mul.update(sz, -sz * rev[a[idx]]), mul.update(sz - 1, (sz - 1) * rev[a[idx]]);
                if(val == a[idx + 1]) {
                    ll l = s[val].order_of_key(idx), ref = l, r = s[val].size() - 1, ans;
                    while(l <= r) {
                        ll mid = (l + r) >> 1;
                        if(idx - *s[val].find_by_order(mid) == ref - mid) {
                            l = mid + 1;
                            ans = mid;
                        }
                        else
                            r = mid - 1;
                    }
                    ll sz = ans - ref + 1;
                    cnt.update(sz, 1 * rev[val]), cnt.update(sz - 1, -1 * rev[val]);
                    mul.update(sz, sz * rev[val]), mul.update(sz - 1, -(sz - 1) * rev[val]);
                }
                else {
                    cnt.update(1, rev[val]);
                    mul.update(1, rev[val]);
                }
            }
            else if(a[idx] == a[idx + 1]) {
                ll ref = s[a[idx]].order_of_key(idx), l = ref, r = s[a[idx]].size() - 1, ans;
                while(l <= r) {
                    ll mid = (l + r) >> 1;
                    if(idx - *s[a[idx]].find_by_order(mid) == ref - mid) {
                        l = mid + 1;
                        ans = mid;
                    }
                    else
                        r = mid - 1;
                }
                ll sz = ans - ref + 1;
                cnt.update(sz, -1 * rev[a[idx]]), cnt.update(sz - 1, 1 * rev[a[idx]]);
                mul.update(sz, -sz * rev[a[idx]]), mul.update(sz - 1, (sz - 1) * rev[a[idx]]);
                if(val == a[idx - 1]) {
                    ll l = 0, ref = s[val].order_of_key(idx), r = ref, ans;
                    while(l <= r) {
                        ll mid = (l + r) >> 1;
                        if(idx - *s[val].find_by_order(mid) == ref - mid) {
                            r = mid - 1;
                            ans = mid;
                        }
                        else
                            l = mid + 1;
                    }
                    ll sz = ref - ans + 1;
                    cnt.update(sz, 1 * rev[val]), cnt.update(sz - 1, -1 * rev[val]);
                    mul.update(sz, sz * rev[val]), mul.update(sz - 1, -(sz - 1) * rev[val]);
                }
                else {
                    cnt.update(1, rev[val]);
                    mul.update(1, rev[val]);
                }
            }
            else {
                if(val == a[idx - 1] && val == a[idx + 1]) {
                    // find left size and right size
                    ll ref = s[val].order_of_key(idx);
                    ll l = ref, r = s[val].size() - 1, lans, rans;
                    //cout << l << " " << r << endl;
                    //for(auto i : s[val])
                    //    cout << i << " ";
                    //cout << endl;
                    while(l <= r) {
                        ll mid = (l + r) >> 1;
                        //cout << mid << endl;
                        //cout << idx << " " << *s[val].find_by_order(mid) << " " << ref << " " << mid << endl;
                        if(idx - *s[val].find_by_order(mid) == ref - mid) {
                            //cout << "FOUND " << mid << endl;
                            l = mid + 1;
                            rans = mid;
                        }
                        else
                            r = mid - 1;
                    }
                    l = 0, r = ref;
                    while(l <= r) {
                        ll mid = (l + r) >> 1;
                        if(idx - *s[val].find_by_order(mid) == ref - mid) {
                            r = mid - 1;
                            lans = mid;
                        }
                        else
                            l = mid + 1;
                    }
                    //cout << lans << " " << ref << " " << rans << endl;
                    cnt.update(ref - lans, -1 * rev[val]), cnt.update(rans - ref, -1 * rev[val]), cnt.update(1, -1 * rev[a[idx]]), cnt.update(rans - lans + 1, 1 * rev[val]);
                    mul.update(ref - lans, -(ref - lans) * rev[val]), mul.update(rans - ref, -(rans - ref) * rev[val]), mul.update(1, -1 * rev[a[idx]]), mul.update(rans - lans + 1, (rans - lans + 1) * rev[val]);
                    //cout << "TEST" << endl;
                }
                else if(val == a[idx + 1]) {
                    ll l = s[val].order_of_key(idx), ref = l, r = s[val].size() - 1, ans;
                    while(l <= r) {
                        ll mid = (l + r) >> 1;
                        if(idx - *s[val].find_by_order(mid) == ref - mid) {
                            l = mid + 1;
                            ans = mid;
                        }
                        else
                            r = mid - 1;
                    }
                    ll sz = ans - ref + 1;
                    cnt.update(sz, 1 * rev[val]), cnt.update(sz - 1, -1 * rev[val]), cnt.update(1, -rev[a[idx]]);
                    mul.update(sz, sz * rev[val]), mul.update(sz - 1, -(sz - 1) * rev[val]), mul.update(1, -rev[a[idx]]);
                }
                else if(val == a[idx - 1]) {
                    ll l = 0, ref = s[val].order_of_key(idx), r = ref, ans;
                    while(l <= r) {
                        ll mid = (l + r) >> 1;
                        if(idx - *s[val].find_by_order(mid) == ref - mid) {
                            r = mid - 1;
                            ans = mid;
                        }
                        else
                            l = mid + 1;
                    }
                    ll sz = ref - ans + 1;
                    cnt.update(sz, 1 * rev[val]), cnt.update(sz - 1, -1 * rev[val]), cnt.update(1, -rev[a[idx]]);
                    mul.update(sz, sz * rev[val]), mul.update(sz - 1, -(sz - 1) * rev[val]), mul.update(1, -rev[a[idx]]);
                }
                else {
                    cnt.update(1, -rev[a[idx]]);
                    cnt.update(1, rev[val]);
                    mul.update(1, -rev[a[idx]]);
                    mul.update(1, rev[val]);
                }
            }
            s[a[idx]].erase(idx);
            a[idx] = val;
            
        }
        else {
            ll x = queries[i].se.fi;
            cout << (long long)(mul.query(x, lim - 1) - cnt.query(x, lim - 1) * (x - 1)) * (long long)x << endl;
        }
        /*
        for(ll i = 1; i <= n; ++i)
            cout << (long long)cnt.query(i, i) << " ";
        cout << endl;
        for(ll i = 1; i <= n; ++i)
            cout << (long long)mul.query(i, i) << " ";
        cout << endl;
        */
    }
    return 0;
}