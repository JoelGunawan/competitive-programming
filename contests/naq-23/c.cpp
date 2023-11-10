// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int lim = 1e6 + 5;
struct fenwick {
    long long a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void update(int idx, int val) {
        while(idx < lim) {
            a[idx] += val;
            idx += (idx&-idx);
        }
    }
    long long query(int idx) {
        long long res = 0;
        while(idx > 0) {
            res += a[idx];
            idx -= (idx&-idx);
        }
        return res;
    }
    long long query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
fenwick bit;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    // fi -> cnt
    // se -> expired
    pair<int, int> a[n + 1];
    ll sum = 0;
    for(int i = 1; i <= n; ++i) {
        int q, f;
        cin >> q >> f;
        a[i] = mp(q, f);
        if(q > 0) {
            bit.update(i, 1);
            bit.update(f + 1, -1);
        }
        sum += q;
        
    }
    bool valid = 1;
    for(int i = 1; i <= n; ++i) {
        if(bit.query(i) == 0)
            valid = 0;
    }
    if(!valid) {
        cout << -1 << endl;
        return 0;
    }
    long double l = 0, r = (long double)sum / n + 1;
    cout << fixed << setprecision(15);
    // use fractions?
    // in the form of fraction over 1e10
    while((r - l) > max((long double)1e-10, (r - l) / 1e10)) {
        long double mid = (l + r) / 2.0;
        priority_queue<pair<int, long double>, vector<pair<int, long double>>, greater<pair<int, long double>>> pq;
        bool pos = 1;
        for(int i = 1; i <= n; ++i) {
            pq.push(mp(a[i].se, a[i].fi));
            long double cur = mid;
            while(pq.size() && cur > 0) {
                // expired case
                while(pq.size() && pq.top().fi < i) {
                    pq.pop();
                }
                if(pq.size()) {
                    if(pq.top().se >= cur) {
                        pair<int, long double> tmp = pq.top();
                        tmp.se -= mid;
                        pq.pop();
                        pq.push(tmp);
                        cur = -1;
                    }
                    else {
                        cur -= pq.top().se;
                        pq.pop();
                    }
                }
            }
            if(cur > 0) {
                pos = 0;
                break;
            }
        }
        if(pos)
            l = mid;
        else
            r = mid;
    }
    cout << (l + r) / (2 * k) << endl;
    //cout << 1.0 / 1e6 / 39 << endl;
    return 0;
}