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
    // do k == 0 case
    // simplify s = 1 is allowed unless s = 0 then output 1
    /*
    ll k, s, n;
    cin >> k >> s >> n;
    if(s == 0)
        cout << 1 << endl;
    else {
        // do as if s = 1
        // there is literally no difference
        // semua total yang mungkin
        cout << n * (n - 1) / 2 + 1 << endl;
    }
    */
    // do s == 1 case
    ll k, s, n;
    cin >> k >> s >> n;
    ll a[n + 1];
    a[0] = 0;
    for(int i = 1; i <= n; ++i)
        a[i] = s * (i - 1) + a[i - 1];
    pair<ll, ll> segments[n + 1];
    vector<pair<ll, bool>> sweep;
    for(int i = 0; i <= n; ++i) {
        // pake k i kali
        // determine min and max
        ll tmp = i * k - (n - i) * k;
        // a[0] -> null value
        // k elemen pertama dikurangi n - k elemen terakhir
        // a[k] - (a[n] - a[k])
        // k elemen terakhir dikurangi n - k elemen pertama
        // (a[n] - a[n - k]) - a[n - k]
        segments[i] = mp(tmp + a[i] - (a[n] - a[i]), tmp + (a[n] - a[n - i]) - a[n - i]);
        if(segments[i].fi > segments[i].se)
            swap(segments[i].fi, segments[i].se);
        //cout << segments[i].fi << " " << segments[i].se << endl;
        sweep.pb(mp(segments[i].fi, 0));
        sweep.pb(mp(segments[i].se, 1));
    }
    sort(sweep.begin(), sweep.end());
    ll odd_active = 0, odd_last, even_active = 0, even_last;
    ll res = 0;
    for(auto i : sweep) {
        if(!i.se) {
            if(i.fi & 1) {
                if(odd_active == 0)
                    odd_last = i.fi;
                ++odd_active;
            }
            else {
                if(even_active == 0)
                    even_last = i.fi;
                ++even_active;
            }
        }
        else {
            if(i.fi & 1) {
                --odd_active;
                if(odd_active == 0)
                    res += (i.fi - odd_last) / 2 + 1;
            }
            else {
                --even_active;
                if(even_active == 0)
                    res += (i.fi - even_last) / 2 + 1;
            }
        }
        //cout << i.fi << " " << active << endl;
    }
    cout << res << endl;
    return 0;
}