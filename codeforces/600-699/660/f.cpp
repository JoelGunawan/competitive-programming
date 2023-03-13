#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    // cost of subarray -> pref1[b] - pref1[a - 1] - (pref2[b] - pref2[a - 1]) * (a - 1)
    // pref1[b] - pref1[a - 1] + pref2[a - 1] * (a - 1)-> c
    // x -> pref2[b]
    // m -> -(a - 1)
    ll pref1[n + 1], pref2[n + 1];
    memset(pref1, 0, sizeof(pref1)); memset(pref2, 0, sizeof(pref2));
    for(int i = 1; i <= n; ++i) {
        pref1[i] = pref1[i - 1] + 1ll * a[i] * i;
        pref2[i] = pref2[i - 1] + a[i];
    }
    vector<pair<ll, ll>> cht;
    cht.pb(mp(0, 0));
    ll res = 0;
    for(int i = 1; i <= n; ++i) {
        int l = 0, r = cht.size() - 1;
        // slope semakin besar -> const semakin kecil
        // smaller index smaller slope
        //cout << "PROC " << i << endl;
        while(l < r) {
            int m1 = l + (r - l) / 3, m2 = l + 2 * (r - l) / 3;
            if(m1 == m2)
                ++m2;
            //cout << m1 << " " << cht[m1].fi << " " << pref2[i] << " " << cht[m1].se << endl;
            //cout << m1 << " " << cht[m1].fi * pref2[i] + cht[m1].se << " " << m2 << " " << cht[m2].fi * pref2[i] + cht[m2].se << endl;
            // try evaluate maximum by finding left rightnya
            if(cht[m1].fi * pref2[i] + cht[m1].se > cht[m2].fi * pref2[i] + cht[m2].se)
                r = m2 - 1;
            else
                l = m1 + 1;
        }
        res = max(res, cht[l].fi * pref2[i] + cht[l].se + pref1[i]);
        pair<ll, ll> tmp = mp(-i, -pref1[i] + pref2[i] * i);
        while(cht.size() >= 2 && (tmp.se - cht[cht.size() - 2].se) / (cht[cht.size() - 2].fi - tmp.fi) 
        >= (cht.back().se - cht[cht.size() - 2].se) / (cht[cht.size() - 2].fi - cht.back().fi))
            cht.pop_back();
        cht.pb(tmp);
        //cout << cht.size() << " " << tmp.fi << " " << tmp.se << endl;
    }
    cout << res << endl;
}