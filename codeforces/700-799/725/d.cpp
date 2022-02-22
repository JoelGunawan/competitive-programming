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
    ll t, trash;
    cin >> t >> trash;
    vector<pair<ll, ll>> a(n - 1);
    for(int i = 0; i < n - 1; ++i) {
        ll x, y;
        cin >> x >> y;
        a[i] = mp(x, y + 1 - x);
    }
    sort(a.begin(), a.end());
    multiset<ll> req;
    int res = INT_MAX;
    while(true) {
        bool changed = 0;
        while(a.size() > 0 && a.back().fi > t)
            req.ins(a.back().se), a.pop_back();
        res = min(res, (int)req.size() + 1);
        if(req.size() == 0) {
            res = 1; 
            break;
        }
        else {
            if(t < *req.begin())
                break;
            t -= *req.begin(), req.erase(req.begin());
            while(a.size() > 0 && a.back().fi > t) {
                req.ins(a.back().se), a.pop_back();
            }
            res = min(res, (int)req.size() + 1);
        }
    }
    cout << res << endl;
    return 0;
}