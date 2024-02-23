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
const int lim = 1e5 + 5;
struct fenwick {
    lll a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void update(int idx, lll val) {
        while(idx < lim) {
            a[idx] += val;
            idx += idx&-idx;
        }
    }
    lll query(int idx) {
        lll ret = 0;
        while(idx) {
            ret += a[idx];
            idx -= idx&-idx;
        }
        return ret;
    }
    lll query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
lll pref1[lim], pref2[lim];
// return actual k prefix
lll get_prefk(int l, int r) {
    if(l > r)
        return 0;
    return pref1[r] - pref1[l - 1];
}
// return weighted prefix
lll get_prefw(int l, int r) {
    if(l > r)
        return 0;
    return pref2[r] - pref1[l - 1] - (r - l + 1) * get_prefk(1, l - 1);
}
void output(lll a) {
    string s = "";
    while(a) {
        s += (char)((a % 10) + '0');
        a /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    ll a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    int k[n + 1];
    }
    for(int i = 1; i < n; ++k)
        cin >> k[i];
    for(int i = 1; i <= n; ++i) {
        pref1[i] = pref1[i - 1] + k[i];
        pref2[i] = pref2[i - 1] + pref1[i];
    }
    k[n] = 0;
    // l, r
    set<pair<int, int>> s;
    for(int i = 1; i <= n; ++i)
        s.ins(mp(i, i));
    for(int que = 1; que <= q; ++que) {
        char type;
        cin >> type;
        if(type == '+') {
            int i, x;
            cin >> i >> x;
            if(x == 0)
                continue;
            pair<int, int> cur;
            cur = *--s.ub(mp(i, 1e9));
            if(cur.fi != i) {
                // unmerge
                bit.update(cur.fi, -bit.query(cur.fi, cur.fi));
                // recalculate on the segment cur.fi to i - 1
                bit.update(cur.fi, get_prefw(cur.fi, i - 1) + (lll)(i - cur.fi) * a[l]);
                // set a[i]
                a[i] = get_prefk(cur.fi, i - 1) + a[cur.fi];
                s.erase(cur);
                s.ins(mp(cur.fi, i - 1));
                s.ins(mp(i, cur.se));
            }
            // recalculate from i to cur.se
            a[i] += x;
            bit.update(i, get_prefw(i, cur.se - 1) + (lll)(cur.se - i + 1) * a[i]);
            while(*--s.end() != cur) {
                pair<int, int> nxt = *s.ub(mp(i, 1e9));
                if(a[i] + get_prefk(i, nxt.fi - 1) >= a[nxt.fi]) {
                    // merge
                    bit.update(i, -bit.query(i, i));
                    bit.update(i, get_prefw(i, nxt.se - 1) + (lll)(nxt.se - i + 1) * a[i]);
                    s.erase(nxt);
                    s.erase(s.lb(mp(i, 0)));
                    s.ins(mp(i, nxt.se));
                }
                else
                    break;
            }
        }
        else {
            int l, r;
            cin >> l >> r;
            // find last segment and first segment
            pair<int, int> left, right;
            left = *--s.ub(mp(l, 1e9));
            right = *--s.ub(mp(r, 1e9));
            if(left == right) {
                // special case
                // do query manually within one segment
                output(get_prefw(left.fi, r) - get_prefw(left.fi, l - 1) + (lll)a[i] * (r - l + 1));
            }
            else {
                // query left segment individually
                // query right segment individually
                // add everything in middle

            }
        }
    }

    return 0;
}