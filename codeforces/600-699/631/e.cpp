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
#define ld long double
using namespace std;
struct line {
    ll m = 0, c = 0;
    line(ll a, ll b) {
        m = a, c = b;
    }
    ll eval(ll x) {
        return m * x + c;
    }
    ld intersect(line a) {
        return (ld)(c - a.c) / (a.m - m);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    ll pref[n];
    pref[0] = a[0];
    for(int i = 1; i < n; ++i)
        pref[i] = pref[i - 1] + a[i];
    vector<line> cht;
    ll dp[n];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; ++i) {
        line tmp(0, 0);
        tmp.m = i + 1;
        if(i == 0)
            tmp.c = 0;
        else
            tmp.c = -pref[i - 1];
        while(cht.size() > 1 && tmp.intersect(cht[cht.size() - 2]) <= cht.back().intersect(cht[cht.size() - 2]))
            cht.pop_back();
        cht.pb(tmp);
        int l = 0, r = cht.size() - 1, ans = -1;
        while(l <= r) {
            int mid = (l + r) / 2;
            ld cl, cr;
            if(mid == 0)
                cl = -1e18;
            else
                cl = cht[mid].intersect(cht[mid - 1]);
            if(mid == cht.size() - 1)
                cr = 1e18;
            else
                cr = cht[mid].intersect(cht[mid + 1]);
            if(cl <= a[i] && cr >= a[i]) {
                ans = mid;
                break;
            }
            else if(cr < a[i]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        if(ans != -1 && i != 0)
            dp[i] = cht[ans].eval(a[i]) + pref[i - 1] - a[i] * (i + 1);
        //cout << dp[i] << " " << cht[ans].m << " " << cht[ans].c << endl;
    }
    //cout << endl;
    cht.clear();
    for(int i = n - 1; i >= 0; --i) {
        int l = 0, r = cht.size() - 1, ans = -1;
        //cout << "LINES" << endl;
        //for(auto i : cht)
        //    cout << i.m << " " << i.c << endl;
        //cout << "BINSER" << endl;
        while(l <= r) {
            // semakin ke kanan, gradien semakin turun
            // berarti intersect semakin naik
            int mid = (l + r) / 2;
            ld cl, cr;
            if(mid == cht.size() - 1)
                cl = -1e18;
            else
                cl = cht[mid].intersect(cht[mid + 1]);
            if(mid == 0)
                cr = 1e18;
            else
                cr = cht[mid].intersect(cht[mid - 1]);
            //cout << mid << " " << cl << " " << cr << endl;
            if(a[i] >= cl && a[i] <= cr) {
                ans = mid;
                break;
            }
            else if(cr < a[i])
                r = mid - 1;
            else
                l = mid + 1;
        }
        if(ans != -1 && i != n - 1) {
            //cout << "EVAL" << endl << cht[ans].eval(a[i]) - a[i] * (i + 1) + pref[i] << " " << cht[ans].m << " " << cht[ans].c << endl;
            dp[i] = max(dp[i], cht[ans].eval(a[i]) - a[i] * (i + 1) + pref[i]);
        }
        line tmp(i + 1, -pref[i]);
        while(cht.size() > 1 && tmp.intersect(cht[cht.size() - 2]) >= cht.back().intersect(cht[cht.size() - 2]))
            cht.pop_back();
        cht.pb(tmp);
    }
    ll res = 0;
    for(int i = 0; i < n; ++i)
        res = max(res, dp[i]);
    ll sum = 0;
    for(int i = 0; i < n; ++i)
        sum += a[i] * (i + 1);
    cout << sum + res << endl;
    return 0;
}