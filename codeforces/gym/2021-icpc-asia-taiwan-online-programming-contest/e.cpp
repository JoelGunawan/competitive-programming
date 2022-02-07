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
#define ld long double
using namespace std;
ld f(ld mid) {
    return pow(mid, 2) * pow(mid + 1, 2) * (2 * pow(mid, 2) + 2 * mid - 1) / 12;
}
int main() {
    cout << fixed << setprecision(0);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ld q, p;
    cin >> p >> q;
    ld l = 0, r = 1e50, res = 1e50;
    while(l <= r) {
        ld mid = floor((l + r) / 2);
        if(f(mid) * q >= p * mid) {
            r = mid - 1, res = mid;
        }
        else {
            l = mid + 1;
        }
    }
    res -= 1;
    res = max(res, (ld)0.0);
    res = round(res);
    cout << -(f(res) * q - p * res) + p << endl;
    l = 0, r = 1e50;
    while(l <= r) {
        ld mid = floor((l + r) / 2);
        if(f(mid) * q - p * mid >= 1e99) {
            r = mid - 1, res = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << res << endl;
    return 0;
}