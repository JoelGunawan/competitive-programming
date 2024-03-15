#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll cross(pair<ll, ll> a, pair<ll, ll> b) {
    return a.first * b.second - b.first * a.second;
}
int main() {
    int n;
    cin >> n;
    ll res = 0;
    pair<int, int> a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    for(int i = 1; i <= n; ++i)
        res += cross(a[i], a[(i % n) + 1]);
    res = abs(res);
    cout << res << endl;
}