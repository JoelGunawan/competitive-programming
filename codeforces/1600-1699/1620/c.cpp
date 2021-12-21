// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
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
void tc() {
    int n, k; ll x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    int cnt = 0;
    vector<int> a;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '*')
            ++cnt;
        else if(cnt > 0) {
            a.pb(cnt), cnt = 0;
        }
    }
    if(cnt > 0)
        a.pb(cnt);
    lll tmp = 1;
    // start from the back
    vector<pair<int, lll>> cur;
    for(int i = a.size() - 1; i >= 0; --i) {
        cur.pb(mp(a[i] * k, tmp));
        if(tmp > x)
            break;
        tmp *= (a[i] * k + 1);
    }
    vector<ll> sizes;
    tmp = x;
    --tmp;
    reverse(cur.begin(), cur.end());
    for(int i = 0; i < cur.size(); ++i) {
        sizes.pb(tmp / cur[i].se);
        tmp %= cur[i].se;
    }
    reverse(sizes.begin(), sizes.end());
    int idx = 0;
    string res = "";
    for(int i = n - 1; i >= 0; --i) {
        if(s[i] == '*') {
            if(idx < sizes.size()) {
                for(int j = 0; j < sizes[idx]; ++j)
                    res += 'b';
                ++idx;
                while(i > 0 && s[i - 1] == '*')
                    --i;
            }
        }
        else
            res += s[i];
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}