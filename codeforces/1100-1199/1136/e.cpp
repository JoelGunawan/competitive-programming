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
#define lll long long
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
        if(idx == 0)
            return;
        while(idx < lim) {
            a[idx] += val;
            idx += idx&-idx;
        }
    }
    lll query(int idx) {
        lll ret = 0;
        if(idx < 0)
            return 0;
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
    return pref2[r - 1] - pref2[l - 1] - (r - l) * get_prefk(1, l - 1);
}
lll abs(lll a) {
    return a < 0 ? -a : a;
}
void output(lll a) {
    string s = "";
    bool neg = a < 0;
    while(a) {
        s += (abs(a % 10) + '0');
        a /= 10;
    }
    reverse(s.begin(), s.end());
    if(s.size() == 0)
        s = "0";
    if(neg)
        s = "-" + s;
    cout << s << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    fenwick bit;
    int n;
    cin >> n;
    ll a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        bit.update(i, a[i]);
    }
    int k[n + 1];
    for(int i = 1; i < n; ++i)
        cin >> k[i];
    for(int i = 1; i <= n; ++i) {
        pref1[i] = pref1[i - 1] + k[i];
        pref2[i] = pref2[i - 1] + pref1[i];
    }
    k[n] = 0;
    // l, r
    int q;
    cin >> q;
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
                bit.update(cur.fi, get_prefw(cur.fi, i - 1) + (lll)(i - cur.fi) * a[cur.fi]);
                // set a[i]
                a[i] = get_prefk(cur.fi, i - 1) + a[cur.fi];
                s.erase(cur);
                s.ins(mp(cur.fi, i - 1));
                s.ins(mp(i, cur.se));
            }
            // recalculate from i to cur.se
            a[i] += x;
            //cout << "A VAL " << i << " " << a[i] << endl;
            //cout << get_prefw(i, cur.se) << " " << cur.se - i + 1 << " " << a[i] << endl;
            //cout << "NEW " << get_prefw(i, cur.se) + (lll)(cur.se - i + 1) * a[i] << endl;
            bit.update(i, -bit.query(i, i));
            bit.update(i, get_prefw(i, cur.se) + (lll)(cur.se - i + 1) * a[i]);
            // cout << "DONE RECALC" << endl;
            // cout.flush();
            while(s.size() && (--s.end())->fi != i) {
                pair<int, int> nxt = *s.ub(mp(i, 1e9));
                // cout << "SIZE " << s.size() << " " << nxt.fi << " " << nxt.se << endl;
                if(a[i] + get_prefk(i, nxt.fi - 1) >= a[nxt.fi]) {
                    // merge
                    bit.update(i, -bit.query(i, i));
                    bit.update(nxt.fi, -bit.query(nxt.fi, nxt.fi));
                    bit.update(i, get_prefw(i, nxt.se) + (lll)(nxt.se - i + 1) * a[i]);
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
                //cout << "QUERY " << que << " " << l << " " << r << endl;
                output(get_prefw(left.fi, r) - get_prefw(left.fi, l - 1) + (lll)a[left.fi] * (r - l + 1));
            }
            else {
                // query left segment individually
                // query right segment individually
                // add everything in middle
                lll res = bit.query(left.se + 1, right.fi - 1);
                //cout << "MID " << res << endl;
                //cout << "LEFT RANGE " << left.fi << " " << left.se << endl;
                if(left.fi == l) {
                    res += bit.query(left.fi, left.se);
                    //cout << "LEFT " << bit.query(left.fi, left.se) << endl;
                }
                else {
                    //cout << "LEFT " << get_prefw(left.fi, left.se) - get_prefw(left.fi, l - 1) + (lll)a[left.fi] * (left.se - l + 1) << endl;
                    res += get_prefw(left.fi, left.se) - get_prefw(left.fi, l - 1) + (lll)a[left.fi] * (left.se - l + 1);
                }
                //cout << "RIGHT RANGE " << right.fi << " " << right.se << endl;
                if(right.se == r) {
                    res += bit.query(right.fi, right.se);
                    //cout << "RIGHT " << bit.query(right.fi, right.se) << endl;
                }
                else {
                    res += get_prefw(right.fi, r) + (lll)a[right.fi] * (r - right.fi + 1);
                }
                output(res);
            }
        }
    }

    return 0;
}