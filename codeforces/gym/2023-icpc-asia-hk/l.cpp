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
const int lim = 2e5 + 5;
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
void tc() {
    int n, m, k;
    cin >> n >> m >> k;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int b[m + 1];
    for(int i = 1; i <= m; ++i) 
        cin >> b[i];
    int c[k + 1];
    for(int i = 1; i <= k ;++i)
        cin >> c[i];
    for(int i = 1; i <= n; ++i)
        bit.update(i, -bit.query(i, i) + 1);
    // check whether b is subsequence of a
    int pos[n + 1];
    for(int i = 1; i <= n; ++i)
        pos[a[i]] = i;
    vector<int> p;
    for(int i = 1; i <= m; ++i)
        p.pb(pos[b[i]]);
    for(int i = 0; i < p.size() - 1; ++i) {
        if(p[i + 1] < p[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    bool ex[n + 1];
    memset(ex, 0, sizeof(ex));
    for(int i = 1; i <= m; ++i)
        ex[b[i]] = 1;
    vector<int> st;
    int l[n + 1], r[n + 1];
    for(int i = 1; i <= n; ++i) {
        if(ex[a[i]]) {
            while(st.size() && a[st.back()] < a[i])
                st.pop_back();
            st.pb(i);
        }
        else {
            if(st.empty() || a[i] > a[st[0]])
                l[i] = 1;
            else {
                // binary search the most right stack position where a[st[idx]] > a[i]
                int cl = 0, cr = st.size() - 1, res = -1;
                while(cl <= cr) {
                    int mid = (cl + cr) / 2;
                    if(a[st[mid]] > a[i]) {
                        res = mid, cl = mid + 1;
                    }
                    else
                        cr = mid - 1;
                }
                if(res == -1)
                    l[i] = 1;
                else
                    l[i] = st[res] + 1;
            }
        }
    }
    st.clear();
    for(int i = n; i >= 1; --i) {
        if(ex[a[i]]) {
            while(st.size() && a[st.back()] < a[i])
                st.pop_back();
            st.pb(i);
        }
        else {
            if(st.empty() || a[i] > a[st[0]])
                r[i] = n;
            else {
                // binary search the most right stack position where a[st[idx]] > a[i]
                int cl = 0, cr = st.size() - 1, res = -1;
                while(cl <= cr) {
                    int mid = (cl + cr) / 2;
                    if(a[st[mid]] > a[i]) {
                        res = mid, cl = mid + 1;
                    }
                    else
                        cr = mid - 1;
                }
                if(res == -1)
                    r[i] = n;
                else
                    r[i] = st[res] - 1;
            }
        }
    }
    sort(c + 1, c + k + 1);
    reverse(c + 1, c + k + 1);
    vector<pair<int, int>> v;
    for(int i = 1; i <= n; ++i) {
        if(!ex[a[i]])
            v.pb(mp(a[i], i));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    vector<int> cnt;
    for(auto i : v) {
        // find count left and right
        cnt.pb(bit.query(l[i.se], r[i.se]));
        bit.update(i.se, -1);
    }
    sort(cnt.begin(), cnt.end());
    reverse(cnt.begin(), cnt.end());
    multiset<int> vals;
    for(int i = 1; i <= k; ++i) {
        vals.ins(c[i]);
    }
    if(cnt.size() > k) {
        cout << "NO" << endl;
        return;
    }
    for(int i = 0; i < cnt.size(); ++i) {
        //cout << c[i + 1] << " " << cnt[i] << endl;
        // cari apa ada yg <= cnt[i] di vals
        if(vals.ub(cnt[i]) == vals.begin()) {
            cout << "NO" << endl;
            return;
        }
        else
            vals.erase(--vals.ub(cnt[i]));
    }
    cout << "YES" << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // start from maximum, find largest magic wand possible, then delete element
    // segtree binser
    int t;
    cin >> t;
    while(t--) {
        tc();
    }    
    return 0;
}