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
int mod = 1e9 + 7;
ll mul(ll a, ll b) {
    a %= mod;
    b %= mod;
    return (a * b) % mod;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n + 5];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    ll pref[n + 1];
    memset(pref, 0, sizeof(pref));
    a[0] = 1e9 + 5;
    for(int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i];
        pref[i] %= mod;
    }
    ll suff[n + 2];
    ll csuff[n + 2];
    memset(suff, 0, sizeof(suff));
    memset(csuff, 0, sizeof(csuff));
    for(int i = n; i >= 1; --i) {
        suff[i] = suff[i + 1] + a[i];
        suff[i] %= mod;
        csuff[i] = csuff[i + 1] + suff[i];
        csuff[i] %= mod;
    }
    ll stack_sum = 0, mx_sum = 0, res = 0;
    vector<int> s = {0};
    for(int i = 1; i <= n; ++i) {
        while(a[i] >= a[s.back()]) {
            //cout << "OLD " << stack_sum << endl;
            //cout <<  (a[i] - a[s.back()]) << " " << csuff[s[s.size() - 2] + 1] - csuff[i] - suff[i] * (i - s[s.size() - 2] - 1) << endl;
            stack_sum += mul((a[i] - a[s.back()]), (csuff[s[s.size() - 2] + 1] - csuff[i] - mul(suff[i], (i - s[s.size() - 2] - 1)) - ((csuff[s.back() + 1] - csuff[i] - mul(suff[i], (i - s.back() - 1))))));
            mx_sum += 1ll * (a[i] - a[s.back()]) * (s.back() - s[s.size() - 2]);
            //cout << "NEW " << stack_sum << endl;
            stack_sum %= mod;
            mx_sum %= mod;
            s.pop_back();
        }
        //cout << mx_sum << " " << stack_sum << endl;
        mx_sum += a[i];
        mx_sum %= mod;
        stack_sum += mul(mx_sum, a[i]);
        stack_sum %= mod;
        s.pb(i);
        //cout << stack_sum << endl;
        res = (res + stack_sum) % mod;
    }
    //cout << endl;
    if(res < 0)
        res += mod;
    cout << res << endl;
    return 0;
}