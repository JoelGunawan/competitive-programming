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
    int n, p;
    cin >> n >> p;
    int cnt[n + 1];
    map<pair<int, int>, int> pcnt;
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if(x > y)
            swap(x, y);
        ++pcnt[mp(x, y)];
        ++cnt[x], ++cnt[y];
    }   
    // check for pairs
    // since there might be instances where it is not possible
    vector<int> counts(n);
    for(int i = 1; i <= n; ++i)
        counts[i - 1] = cnt[i];
    sort(counts.begin(), counts.end());
    ll res = 0;
    for(int i = 1; i < n; ++i) {
        // check semua indeks kurang dari i
        res += max(0, (int)(counts.begin() + i - lower_bound(counts.begin(), counts.end(), p - counts[i])));
        //cout << res << endl;
    }
    for(auto i : pcnt) {
        if(cnt[i.fi.fi] + cnt[i.fi.se] - i.se < p && cnt[i.fi.fi] + cnt[i.fi.se] >= p)
            --res;
    }
    cout << res << endl;
    return 0;
}