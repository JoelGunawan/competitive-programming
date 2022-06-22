// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    ll n, k;
    cin >> n;
    ll a[n], b[n];
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    for(ll i = 0; i < n; ++i)
        cin >> b[i];
    ll up = 0, down = 0;
    for(ll i = 0; i < n; ++i) {
        if(a[i] > b[i])
            ++up;
        else if(a[i] < b[i])
            ++down;
    }
    if((up && !down) || (!up && down))
        cout << "NO" << endl;
    else {
        ll ans[n];
        memset(ans, 0, sizeof(ans));
        vector<pair<ll, ll>> upadd, downadd;
        // bagi jadi up sama down
        // simplify up and down jadi 1 aja
        // terus cari common rationya :D
        ll upa = 0, upb = 0, downa = 0, downb = 0;
        for(ll i = 0; i < n; ++i) {
            if(a[i] > b[i]) {
                // update up
                if(!upa)
                    upa = a[i], upb = b[i];
                else {
                    // kalo misal kanan yang tambah, tambah langsung, else simpan range update
                    if(a[i] == upb)
                        upb = b[i];
                    else if(a[i] > upb) {
                        upa += a[i] - upb;
                        upadd.pb(mp(a[i] - upb, i));
                        upb = b[i];
                    }
                    else {
                        ans[i] += upb - a[i];
                        upb = b[i] + ans[i];
                    }
                }
            }
            else if(a[i] < b[i]) {
                if(!downa)
                    downa = a[i], downb = b[i];
                else {
                    if(a[i] == downb)
                        downb = b[i];
                    else if(a[i] > downb) {
                        downa += a[i] - downb;
                        downadd.pb(mp(a[i] - downb, i));
                        downb = b[i];
                    }
                    else {
                        ans[i] += downb - a[i];
                        downb = b[i] + ans[i];
                    }
                }
            }
        }
        if(upa && downa) {
            ll diffup = upa - upb, diffdown = downb - downa;
            // kelipatan pertama yang lebih besar dari sama dengan
            // samakan upa dan downa
            if(diffup == diffdown) {
                if(upa > downb)
                    downadd.pb(mp(upa - downb, n));
                else
                    upadd.pb(mp(downb - upa, n));
            }
            else if(diffup > diffdown) {
                if(downa < upa)
                    downadd.pb(mp(upa - downa, n)), downb += upa - downa, downa += upa - downa;
                if(downa % diffdown) {
                    downadd.pb(mp(diffdown - downa % diffdown, n));
                    downb += diffdown - downa % diffdown;
                    downa += diffdown - downa % diffdown;
                }
                ll target = downa / diffdown * diffup;
                upadd.pb(mp(target - upb, n));
            }
            else {
                if(upa < downa)
                    upadd.pb(mp(downa - upa, n)), upb += downa - upa, upa += downa - upa;
                if(upa % diffup) {
                    upadd.pb(mp(diffup - upa % diffup, n));
                    upb += diffup - upa % diffup;
                    upa += diffup - upa % diffup;
                }
                ll target = upa / diffup * diffdown;
                downadd.pb(mp(target - downb, n));
            }
        }
        ll tmp1 = 0, tmp2 = 0;
        for(auto i : upadd)
            tmp1 += i.fi;
        for(auto i : downadd)
            tmp2 += i.fi;
        ll idx1 = 0, idx2 = 0;
        for(ll i = 0; i < n; ++i) {
            while(idx1 < upadd.size() && upadd[idx1].se == i)
                tmp1 -= upadd[idx1].fi, ++idx1;
            while(idx2 < downadd.size() && downadd[idx2].se == i)
                tmp2 -= downadd[idx2].fi, ++idx2;
            if(a[i] > b[i])
                ans[i] += tmp1;
            else if(a[i] < b[i])
                ans[i] += tmp2;
        }
        cout << "YES" << endl;
        for(ll i = 0; i < n; ++i)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}