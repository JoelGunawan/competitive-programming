#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    int h[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> h[i];
    // prefix and suffix
    // pref -> ends at x
    // suff -> starts at x
    long long pref[n + 1];
    int cur_r = 1;
    int r[n + 1];
    map<int, int> s;
    ++s[h[1]];
    pref[0] = 0;
    pref[1] = 1;
    for(int i = 1; i <= n; ++i) {
        // find ada berapa prev yang bisa digapai 
        while((cur_r < i) || (cur_r < n && h[cur_r + 1] - (*s.begin()).first <= k && (*--s.end()).first - h[cur_r + 1] <= k)) {
            ++s[h[cur_r + 1]], pref[cur_r + 1] = pref[cur_r] + (cur_r + 1 - i + 1), ++cur_r;
        }
        --s[h[i]];
        if(!s[h[i]])
            s.erase(h[i]);
        r[i] = cur_r;
    }
    int q;
    cin >> q;
    // l paling jauh bisa ke mana?
    // sisanya pake pref
    for(int i = 0; i < q; ++i) {
        int b, e;
        cin >> b >> e;
        // find right furthest from L
        if(r[b] >= e) {
            cout << (1ll * (e - b + 2) * (e - b + 1) >> 1) << endl;
        }
        else {
            // find furthest right from b
            // r[i]
            // sisanya pakai prefix
            cout << pref[e] - pref[r[b]] + (1ll * (r[b] - b + 2) * (r[b] - b + 1) >> 1) << endl;
        }
    }
}