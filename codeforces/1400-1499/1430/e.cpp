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
struct fenwick {
    int a[200001];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    int query(int idx) {
        ll res = 0;
        while(idx > 0)
            res += a[idx], idx -= (idx&-idx);
        return res;
    }
    void upd(int idx, int val) {
        while(idx < 200001)
            a[idx] += val, idx += (idx&-idx);
    }
    int q(int l, int r) {
        return query(r) - query(l - 1);
    }
};
int main() {
    fenwick bit;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; string s;
    cin >> n >> s;
    // get positions of all characters in first and in last
    // find swaps to get it into the positions
    // divide total swaps by 2
    // done :)
    string t = s;
    reverse(t.begin(), t.end());
    vector<int> init[26], last[26];
    for(int i = 0; i < n; ++i) {
        init[s[i] - 'a'].pb(i + 1);
        last[t[i] - 'a'].pb(i + 1);
    }
    // pos in starting array
    int a[n + 1];
    for(int i = 0; i < 26; ++i) {
        for(int j = 0; j < init[i].size(); ++j)
            a[last[i][j]] = init[i][j];
    }
    ll res = 0;
    // start from first to last
    // position of first, position of second, position of third, etc
    for(int i = 1; i < n; ++i) {
        //cout << i << " " << a[i] << " " << actual << endl;
        res += abs((a[i] + bit.query(a[i])) - i);
        bit.upd(1, 1), bit.upd(a[i] + 1, -1);
    }
    cout << res << endl;
    return 0;
}