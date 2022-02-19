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
int mod = 998244353;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    map<int, int> first, last;
    for(int i = 0; i < n; ++i) {
        last[a[i]] = i;
    }
    for(int i = n - 1; i >= 0; --i) {
        first[a[i]] = i;
    }
    vector<pair<int, bool>> segments;
    for(auto i : first) {
        if(i.se != last[i.fi]) {
            segments.pb(mp(i.se, 0));
            segments.pb(mp(last[i.fi], 1));
        }
    }
    sort(segments.begin(), segments.end());
    int prev = 0, cnt = 0, reduce = 0, idx = 0;
    while(idx < segments.size()) {
        int cur = segments[idx].fi;
        while(!segments[idx].se && segments[idx].fi == cur) {
            if(cnt == 0)
                prev = segments[idx].fi;
            ++cnt;
            ++idx;
        }
        //cout << cur << " " << cnt << endl;
        while(idx < segments.size() && segments[idx].fi == cur && segments[idx].se) {
            ++idx;
            --cnt;
        }
        //cout << cur << " " << cnt << endl;
        if(cnt == 0)
            reduce += cur - prev;
    }
    //cout << reduce << endl;
    cout << powmod(2, n - reduce - 1) << endl;
    return 0;
}