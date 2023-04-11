#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int n;
    cin >> n;
    pair<ll, ll> a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i].first >> a[i].second;
    // cost -> -a[i].fi + prefval[i] - mn
    // mn -> preval[j] - a[j].fi
    sort(a + 1, a + n + 1);
    ll mn = 0, val = 0, res = 0;
    for(int i = 1; i <= n; ++i) {
        mn = min(mn, val - a[i].first);
        val += a[i].second;
        res = max(res, -a[i].first + val - mn);
    }
    cout << res << endl;
}