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
int sqr(int a) {
    return a * a;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // y = r^2 - x^2
    // atan(y / x) -> theta
    // final remove = theta / 2pi * area - x * y
    int n, r, w, h;
    cin >> n >> r >> w >> h;
    long double pi = acos(-1);
    long double area = pi * r * r;
    long double res = 0;
    for(int i = 1; i <= n; ++i) {
        int x, y, v;
        cin >> x >> y >> v;
        // cari per kuadran
        bool top, bottom, left, right;
        left = (x - r) < 0;
        right = (x + r) > w;
        top = (y - r) < 0;
        bottom = (y + r) > h;
        long double total = 0;
        if(left && top && sqr(x) + sqr(y) <= sqr(r)) {
            total += x * y;
        }
        else {
            total += area / 4;
            if(left) {
                long double dy = sqrt(r * r - x * x);
                long double dx = x;
                // ada dy ada dx, cari sudutnya
                long double exc = atan(dy / dx) / 2 / pi * area - dy * dx / 2;
                total -= exc;
            }
            if(top) {
                long double dy = y;
                long double dx = sqrt(r * r - y * y);
                long double exc = atan(dx / dy) / 2 / pi * area - dy * dx / 2;
                total -= exc;
            }
        }

        //cout << total << endl;
        if(top && right && sqr(w - x) + sqr(y) <= sqr(r)) {
            total += (w - x) * y;
        }
        else {
            total += area / 4;
            if(right) {
                long double dy = sqrt(r * r - (w - x) * (w - x));
                long double dx = w - x;
                // ada dy ada dx, cari sudutnya
                //cout << x << " " << y << " " << atan(dy / dx) << endl;
                //cout << area / 4 << " " << exc << endl;
                long double exc = atan(dy / dx) / 2 / pi * area - dy * dx / 2;
                total -= exc;
            }
            if(top) {
                long double dy = y;
                long double dx = sqrt(r * r - y * y);
                //cout << x << " " << y << " " << atan(dx / dy) << endl;
                //cout << area / 4 << " " << exc << endl;
                long double exc = atan(dx / dy) / 2 / pi * area - dy * dx / 2;
                total -= exc;
            }
        }

        if(left && bottom && sqr(x) + sqr(h - y) <= sqr(r)) {
            total += x * (h - y);
        }
        else {
            total += area / 4;
            if(left) {
                long double dy = sqrt(r * r - x * x);
                long double dx = x;
                // ada dy ada dx, cari sudutnya
                long double exc = atan(dy / dx) / 2 / pi * area - dy * dx / 2;
                total -= exc;
            }
            if(bottom) {
                long double dy = (h - y);
                long double dx = sqrt(r * r - (h - y) * (h - y));
                long double exc = atan(dx / dy) / 2 / pi * area - dy * dx / 2;
                total -= exc;
            }
        }

        if(bottom && right && sqr(w - x) + sqr(h - y) <= sqr(r)) {
            total += (w - x) * (h - y);
        }
        else {
            total += area / 4;
            if(right) {
                long double dy = sqrt(r * r - (w - x) * (w - x));
                long double dx = w - x;
                // ada dy ada dx, cari sudutnya
                //cout << x << " " << y << " " << atan(dy / dx) << endl;
                //cout << area / 4 << " " << exc << endl;
                long double exc = atan(dy / dx) / 2 / pi * area - dy * dx / 2;
                total -= exc;
            }
            if(bottom) {
                long double dy = (h - y);
                long double dx = sqrt(r * r - (h - y) * (h - y));
                //cout << x << " " << y << " " << atan(dx / dy) << endl;
                //cout << area / 4 << " " << exc << endl;
                long double exc = atan(dx / dy) / 2 / pi * area - dy * dx / 2;
                total -= exc;
            }
        }
        //cout << total << endl;
        res += total * v;
    }
    cout << fixed << setprecision(10);
    cout << res / w / h << endl;
    return 0;
}