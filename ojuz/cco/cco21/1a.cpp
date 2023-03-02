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
const int lim = 1e5 + 5;
int block = sqrt(1e5);
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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, k, q;
    cin >> n >> k >> q;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    // max swaps -> (n - 1) * n / 2
    // use inversion counting aja
    // check how many inversions would change
    // between 2 objects, the inversions can be counted from one of them
    // for the smaller one, 
    // for each number, memo inversions?
    // sparse?
    // buat yang >= sqrt(n) -> memo aja inversionnya berapa, at most n (precomp O(nsqrtnlogn))
    // buat yang <= sqrt(n) -> coba brute force, O(nsqrtnlogn)
    // observe: banyak inversion antara 2 elemen tidak mungkin berubah
    // calculate inversion in O(log)
    // use the fact of sqrt
    // sqrt + fofline
    // <= sqrt -> calculate inversion for each number
    // >= sqrt -> use <= sqrt value OR precompute
    ll cnt[k + 1], p[k + 1];
    for(int i = 1; i <= k; ++i)
        p[i] = i;
    memset(cnt, 0, sizeof(cnt));
    vector<int> pos[k + 1];
    for(int i = 1; i <= n; ++i) {
        ++cnt[a[i]], pos[a[i]].pb(i);
    }
    ll diff[q + 1];   
    vector<pair<pair<int, int>, int>> query;
    ll cur = 0;
    fenwick bit;
    for(int i = 1; i <= n; ++i) {
        cur += bit.query(a[i] + 1, lim - 1);
        bit.update(a[i], 1);
    }
    vector<ll> inv[k + 1];
    for(int i = 1; i <= k; ++i) {
        if(cnt[i] > block) {
            int pre[n + 1];
            pre[0] = 0;
            for(int j = 1; j <= n; ++j) {
                pre[j] = pre[j - 1];
                if(a[j] == i)
                    ++pre[j];
            }
            inv[i].pb(0);
            for(int j = 1; j <= k; ++j) {
                ll res = 0;
                if(i != j) {
                    for(auto x : pos[j]) {
                        res += pre[x];
                    }
                }
                inv[i].pb(cnt[i] * cnt[j] - 2 * res);
            }
        }
    }
    for(int i = 1; i <= q; ++i) {
        int j;
        cin >> j;
        if(cnt[p[j]] <= block && cnt[p[j + 1]] <= block) {
            int l = 0, res = 0;
            for(int i = 0; i < pos[p[j]].size(); ++i) {
                while(l < pos[p[j + 1]].size() && pos[p[j + 1]][l] < pos[p[j]][i])
                    ++l;
                res += l;
            }
            diff[i] = cnt[p[j]] * cnt[p[j + 1]] - 2 * res;
        }
        else {
            if(cnt[p[j]] > cnt[p[j + 1]])
                diff[i] = -inv[p[j]][p[j + 1]];
            else
                diff[i] = inv[p[j + 1]][p[j]];
        }
        cur += diff[i];
        cout << abs(cur) << endl;
        swap(p[j], p[j + 1]);
    }
      
    return 0;
}