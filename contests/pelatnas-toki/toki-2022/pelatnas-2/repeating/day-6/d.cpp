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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].fi >> a[i].se;
    sort(a, a + n);
    int bought = 0;
    ll res = 0;
    multiset<int> x;
    for(int i = n - 1; i >= 0; --i) {
        x.insert(a[i].se);
        while(x.size() > 0 && bought + i < a[i].fi) {
            res += *x.begin();
            x.erase(x.begin());
            ++bought;
        }
    }
    cout << res << endl;
    return 0;
}