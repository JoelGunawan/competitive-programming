#include <bits/stdc++.h>
#define fi first 
#define se second
#define ll long long
#define lb lower_bound
#define mp make_pair
#define pb push_back
#define bit(x) (1LL << (x))
#define getbit(x, i) (((x) >> (i)) & 1)
#define ALL(x) x.begin(), x.end()
#define lll __int128_t
using namespace std;

const double pi = acos(-1);
const int oo = 1e9;

template<typename T1, typename T2> bool mini(T1 &a, T2 b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<typename T1, typename T2> bool maxi(T1 &a, T2 b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const ll is_query = -(1LL<<62);
struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;

        // **** May need long double typecasting here
        return (long double)(x->b - y->b)*(z->m - y->m) >= (long double)(y->b - z->b)*(y->m - x->m);
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        // cerr << l.m << " " << l.b << endl;
        return l.m * x + l.b;
    }
};

lll sqr(lll a) {
    return a * a;
}
double cut_point(pair<lll, lll> a, pair<lll, lll> b) {
    return max({(double)a.fi, (double)b.fi, (sqr(a.fi) - sqr(b.fi) + a.se - b.se) / (double)(2 * (a.fi - b.fi))});
}
lll calc_cost(pair<lll, lll> a, lll t) {
    return sqr(a.fi - t) + a.se;
}
const double eps = 1e-11;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<pair<pair<lll, lll>, pair<lll, lll>>> v;
    for(int i = 1; i <= m; ++i) {
        ll a, b, s, e;
        cin >> a >> b >> s >> e;
        v.pb(mp(mp(s, e), mp(a, b)));
    }
    sort(v.begin(), v.end());
    set<pair<lll, lll>> s[n + 5];
    s[1].insert(mp(0, 0));
    lll shortest[n + 1];
    fill(shortest, shortest + n + 1, (lll)1e18);
    shortest[1] = 0;
    HullDynamic hd[n + 5];
    // (t - time)^2 + prev_cost = t^2 - 2 * time * t + time^2 + prev_cost
    s[1].insert(mp(0, 0));
    int cnt[n + 5];
    memset(cnt, 0, sizeof(cnt));
    for(auto p : v) {
        lll t = p.fi.fi, o = p.se.fi, d = p.se.se, dt = p.fi.se;
        while(s[o].size() && (*s[o].begin()).fi <= t) {
          // cerr << "INSERT " << (ll)(*s[o].begin()).fi << " " << (ll)(*s[o].begin()).se << endl;
          hd[o].insert_line(2 * (*s[o].begin()).fi, (*s[o].begin()).se), s[o].erase(s[o].begin());
          ++cnt[o];
        }
        // cerr << "EVAL " << (ll)t << endl;
        if(cnt[o]) {
          lll cur_cost = -hd[o].eval(t) + sqr(t);
          // cout << (ll)d << " " << (ll)cur_cost << endl;
          shortest[d] = min(cur_cost, shortest[d]);
          s[d].insert(mp(dt, -(sqr(dt) + cur_cost)));
        }
        // cerr << "GET CUT " << cut_point(*s[o].begin(), *(++s[o].begin())) << endl;
        // while(s[o].size() >= 2 && t - cut_point(*s[o].begin(), *(++s[o].begin())) > eps) {
        //     s[o].erase(s[o].begin());
        // }
        // // cout << "CHECK " << o << " " << d << endl;
        // if(s[o].empty())
        //     continue;
        // bool valid = 1;
        // // cerr << "USING " << (*s[o].begin()).fi << " " << (*s[o].begin()).se << endl;
        // pair<lll, lll> cur = mp(dt, calc_cost(*s[o].begin(), t));
        // // cerr << o << " " << d << " " << cur.fi << " " << cur.se << endl;
        // shortest[d] = min(shortest[d], cur.se);
        // if(s[d].lb(cur) != s[d].begin() && s[d].lb(cur) != s[d].end()) {
        //     if(cut_point(cur, *s[d].lb(cur)) - cut_point(*(--s[d].lb(cur)), *s[d].lb(cur)) < eps)
        //         valid = 0;
        // }
        // if(valid) {
        //     // cout << "VALID" << endl;
        //     while(s[d].lb(cur) != s[d].begin() && --s[d].lb(cur) != s[d].begin()) {
        //         auto pr2 = --(--s[d].lb(cur));
        //         if(cut_point(*pr2, *(--s[d].lb(cur))) - cut_point(*pr2, cur) > eps)
        //             s[d].erase(--s[d].lb(cur));
        //         else
        //             break;
        //     }
        //     while(s[d].lb(cur) != s[d].end() && ++s[d].lb(cur) != s[d].end()) {
        //         auto nx2 = (++s[d].lb(cur));
        //         if(cut_point(cur, *nx2) - cut_point(cur, *s[d].lb(cur)) < eps)
        //             s[d].erase(s[d].lb(cur));
        //         else
        //             break;
        //     }
        //     s[d].insert(cur);
        // }
    }
    cout << (ll)shortest[n] << endl;
}


