#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ll long long
#define lll __int128
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < m; ++i)
        cin >> b[i];
    vector<int> factors;
    for(int i = 1; i <= sqrt(k); ++i)
        if(k % i == 0) {
            factors.pb(i);
            if(k / i != i)
                factors.pb(k / i);
        }
    vector<int> a_seg, b_seg;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] == 1)
            ++cnt;
        else {
            if(cnt != 0)
                a_seg.pb(cnt);
            cnt = 0;
        }
    }
    if(cnt > 0)
        a_seg.pb(cnt), cnt = 0;
    for(int i = 0; i < m; ++i) {
        if(b[i] == 1)
            ++cnt;
        else {
            if(cnt != 0)
                b_seg.pb(cnt);
            cnt = 0;
        }
    }
    if(cnt > 0)
        b_seg.pb(cnt);
    ll res = 0;
    for(int i = 0; i < factors.size(); ++i) {
        int a_cnt = 0, b_cnt = 0;
        for(int j = 0; j < a_seg.size(); ++j) {
            if(a_seg[j] >= factors[i]) 
                a_cnt += a_seg[j] - factors[i] + 1;
        }
        for(int j = 0; j < b_seg.size(); ++j) {
            if(b_seg[j] >= k / factors[i])
                b_cnt += b_seg[j] - k / factors[i] + 1;
        }
        res += (a_cnt * b_cnt);
    }
    cout << res << endl;
    return 0;
}