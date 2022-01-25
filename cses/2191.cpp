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
ll f(pair<ll, ll> a, pair<ll, ll> b) {
    return a.fi * b.se - b.fi * a.se;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    pair<ll, ll> arr[n];
    for(int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        arr[i] = mp(a, b);
    }
    ll area = 0;
    for(int i = 0; i < n; ++i) {
        // dot product i to (i + 1) % n
        area = area + f(arr[i], arr[(i + 1) % n]);
    }
    cout << abs(area) << endl;
    return 0;
}