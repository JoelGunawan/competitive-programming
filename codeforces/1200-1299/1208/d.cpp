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
const int lim = 200001;
struct fenwick {
    ll a[lim];
    void upd(int idx, int val) {
        while(idx < lim) {
            a[idx] += val;
            idx += (idx&-idx);
        }
    }
    ll query(int idx) {
        ll res = 0;
        while(idx > 0) {
            res += a[idx];
            idx -= (idx&-idx);
        }
        return res;
    }
    ll q(int l, int r) {
        return l == 0 ? query(r) : query(r) - query(l - 1);
    }
};
fenwick bit;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    ll s[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> s[i], bit.upd(i, i);
    int ans[n + 1];
    memset(ans, -1, sizeof(ans));
    for(int i = n; i >= 1; --i) {
        int l = 0, r = n - 1, res;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(bit.query(mid) <= s[i])
                l = mid + 1, res = mid;
            else if(bit.query(mid) > s[i])
                r = mid - 1;
        }
        bit.upd(res + 1, -bit.q(res + 1, res + 1));
        ans[i] = res + 1;
    }
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}