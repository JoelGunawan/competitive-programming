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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // binser
    // model kyk cht
    // bentuknya pasti ada certain apex, di kanan/kirinya decreasing
    int sz;
    while(cin >> sz) {
        int n;
        cin >> n;
        pair<double, double> a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i].fi >> a[i].se;
        double l = 0, r = sz;
        bool ex = 0;
        for(int i = 0; i < n - 1; ++i) {
            if(a[i].fi > a[n - 1].fi && a[i].se > a[n - 1].se) {
                cout << "The cheater cannot win." << endl;
                ex = 1;
                break;
            }
        }
        if(ex)
            continue;
        while(r - l > 1e-9) {
            double mid1 = l + (r - l) / 3, mid2 = l + 2 * (r - l) / 3;
            double ans1 = 1e9, ans2 = 1e9;
            for(int i = 0; i < n - 1; ++i) {
                ans1 = min(ans1, (1/a[i].fi - 1/a[i].se) * mid1 + sz / a[i].se - ((1/a[n - 1].fi - 1/a[n - 1].se) * mid1 + sz / a[n - 1].se));
                ans2 = min(ans2, (1/a[i].fi - 1/a[i].se) * mid2 + sz / a[i].se - ((1/a[n - 1].fi - 1/a[n - 1].se) * mid2 + sz / a[n - 1].se));
            }
            if(ans1 < ans2)
                l = mid1;
            else
                r = mid2;
        }
        double ans = 1e9;
        for(int i = 0; i < n - 1; ++i) {
            ans = min(ans, (1/a[i].fi - 1/a[i].se) * l + sz / a[i].se - ((1/a[n - 1].fi - 1/a[n - 1].se) * l + sz / a[n - 1].se));
        }
        if(ans < 0) {
            cout << "The cheater cannot win." << endl;
            continue;
        }
        l = l * 100;
        l = round(l);
        l /= 100;
        cout << fixed << setprecision(2) << "The cheater can win by " << (int)round(3600*ans) << " seconds with r = " << l << "km and k = " << sz - l << "km." << endl;
    }
    return 0;
}