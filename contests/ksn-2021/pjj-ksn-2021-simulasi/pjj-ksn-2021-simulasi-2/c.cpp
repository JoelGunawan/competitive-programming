#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m, x, l, r;
    cin >> n >> m >> x >> l >> r;
    int vr[n + 1], vc[m + 1];
    for(int i = 1; i <= n; ++i)
        cin >> vr[i];
    for(int i = 1; i <= m; ++i)
        cin >> vc[i];
    int start_y = (l - 1) / m, start_x = l - start_y * m; ++start_y;
    int end_y = (r - 1) / m, end_x = r - end_y * m; ++end_y;
    //cout << start_x << " " << start_y << " " << end_x << " " << end_y << endl;
    // y is correlated with n, x is correlated with m
    if(start_y == end_y)
    {
        multiset<ll> vals;
        for(int i = start_x; i <= end_x; ++i)
            vals.insert(-vc[i]);
        ll res = 0;
        while(x-- && vals.size() > 0)
            res += (ll)*vals.begin() * vr[start_y], vals.erase(vals.begin());
        cout << -res << endl;
        return 0;
    }
    multiset<ll> general_largest;
    for(int i = start_x; i <= m; ++i)
        general_largest.insert(-vc[i] * (ll)vr[start_y]);
    while(general_largest.size() > x)
        general_largest.erase(--general_largest.end());
    multiset<ll> end_maximum;
    for(int i = 1; i <= end_x; ++i)
        general_largest.insert(-vc[i] * (ll)vr[end_y]);
    while(general_largest.size() > x)
        general_largest.erase(--general_largest.end());
    ll tmp[m + 1]; tmp[0] = 0;
    for(int i = 1; i <= m; ++i)
        tmp[i] = vc[i];
    sort(tmp, tmp + m + 1, greater<ll>());
    ll general_maximum[min(m, x)];
    for(int i = 0; i < min(m, x); ++i)
        general_maximum[i] = tmp[i];
    /*for(auto it = general_maximum.begin(); it != general_maximum.end(); ++it)
        cout << *it << endl;
    */
    int idx[n + 1]; memset(idx, 0, sizeof(idx));
    for(int i = 0; i < x; ++i)
    {
        // find the maximum between all idx
        // and insert it to the general largest 
        ll max_val = 0, max_idx = -1;
        for(int j = start_y + 1; j < end_y; ++j)
        {
            if(idx[j] < m && general_maximum[idx[j]] * vr[j] > max_val)
                max_idx = j, max_val = general_maximum[idx[j]] * vr[j];
        }
        if(max_idx != -1)
            general_largest.insert(-max_val), ++idx[max_idx];
    }
    ll res = 0;
    while(general_largest.size() > 0 && x--)
        res += *general_largest.begin(), general_largest.erase(general_largest.begin());
    cout << -res << endl;
    return 0;
}