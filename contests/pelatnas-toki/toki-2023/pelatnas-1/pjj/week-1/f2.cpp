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
pair<int, int> a[200005], tmp[200005];
ll ans = 5e18;
ll sqr(int a) {
    return 1ll * a * a;
}
/*
void f(int l, int r) {
    if(l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    f(l, mid), f(mid + 1, r);
    int midx = -1e9;
    for(int i = l; i <= mid; ++i)
        midx = max(midx, a[i].se);
    int pr = mid + 1, ps = mid + 1;
    deque<int> dq;
    dq.pb(mid + 1);
    for(int i = l; i <= mid; ++i) {
        if(sqr(midx - a[i].se) >= ans)
            continue;
        // cek antara left dan right
        // right pake 2 pointers
        // furhter ps
        while(ps < r && (a[ps].fi < a[i].fi || sqr(a[ps + 1].fi - a[i].fi) < ans)) {
            if(sqr(midx - a[ps + 1].se) < ans)
                dq.pb(ps + 1);
            ++ps;
        }
        // incr pr
        while(pr < r && pr < ps && a[pr + 1].fi < a[i].fi && sqr(a[pr].fi - a[i].fi) >= ans) {
            if(dq.size() && dq.front() == pr)
                dq.pop_front();
            ++pr;
        }
        for(auto j : dq)
            ans = min(ans, sqr(a[i].fi - a[j].fi) + sqr(a[i].se - a[j].se));
    }
    //inplace_merge(a + l, a + mid + 1, a + r + 1);
    int lidx = l, ridx = mid + 1;
    for(int i = l; i <= r; ++i) {
        if(lidx > mid || (ridx <= r && a[ridx] < a[lidx]))
            tmp[i] = a[ridx++];
        else
            tmp[i] = a[lidx++];
    }
    for(int i = l; i <= r; ++i)
        a[i] = tmp[i];
    /*
    vector<pair<int, int>> proc;
    inplace_merge(a + l, a + mid + 1, a + r + 1);
    for(int i = l; i <= r; ++i) {
        if(sqr(midx - a[i].se) < ans)
            proc.pb(a[i]);
    }
    //cout << "cur " << l << " " << r << endl;
    //for(auto i : proc)
    //    cout << i.fi << " " << i.se << endl;
    for(int i = 0; i < proc.size(); ++i) {
        while(pr < i && sqr(proc[pr].fi - proc[i].fi) >= ans)
            ++pr;
        for(int j = pr; j < i; ++j)
            ans = min(ans, sqr(proc[j].fi - proc[i].fi) + sqr(proc[j].se - proc[i].se));
    }
}
*/
void f(int l, int r) {
    if(l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    f(l, mid), f(mid + 1, r);
    vector<int> left, right;
    int midx = -1e9;
    for(int i = l; i <= mid; ++i)
        midx = max(midx, a[i].se);
    vector<pair<int, int>> proc;
    inplace_merge(a + l, a + mid + 1, a + r + 1);
    for(int i = l; i <= r; ++i) {
        if(sqr(midx - a[i].se) < ans)
            proc.pb(a[i]);
    }
    /*
    cout << "cur " << l << " " << r << endl;
    for(auto i : proc)
        cout << i.fi << " " << i.se << endl;
    */
    int pr = 0;
    for(int i = 0; i < proc.size(); ++i) {
        while(pr < i && sqr(proc[pr].fi - proc[i].fi) >= ans)
            ++pr;
        for(int j = pr; j < i; ++j)
            ans = min(ans, sqr(proc[j].fi - proc[i].fi) + sqr(proc[j].se - proc[i].se));
    }
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cout << fixed << setprecision(4);
    while(true) {
        cin >> n;
        if(n == 0)
            return 0;   
        for(int i = 0; i < n; ++i) {
            cin >> a[i].fi >> a[i].se;
        }
        ans = 9e18;
        sort(a, a + n);
        for(int i = 0; i < n; ++i)
            swap(a[i].fi, a[i].se);
        f(0, n - 1);
        if(ans >= 1e8)
            cout << "INFINITY" << endl;
        else {
            double tmp = sqrt(ans);
            tmp *= 1e4;
            tmp = round(tmp);
            tmp /= 1e4;
            cout << tmp << endl;
        }
    }
    return 0;
}