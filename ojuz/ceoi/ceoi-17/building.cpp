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
ll sqr(ll a) {
    return a * a;
}
const ll is_query = -(1LL<<62);
struct line {
    ll m, b;
    mutable function<const line*()> succ;
    bool operator<(const line &rhs) const {
        if(rhs.b != is_query) 
            return m < rhs.m;
        const line* s = succ();
        if(!s)
            return 0;
        ll x = rhs.m;
        return b - s -> b < (s -> m - m) * x;
    }
};
struct dynamic_hull : public multiset<line> {
    const ll inf = LLONG_MAX;
    bool bad(iterator y) {
        auto z = next(y);
        // basically if the line is the same
        // if the line is the same then we will pick the lower line
        if(y == begin()) {
            if(z == end()) return 0;
            return y -> m == z -> m && y -> b <= z -> b;
        }
        auto x = prev(y);
        if(z == end()) {
            return y -> m == x -> m && y -> b <= x -> b;
        }
        // v1 is with prev
        ll v1 = (x -> b - y -> b);
        // check in case slope is same
        if(y -> m == x -> m) 
            v1 = x -> b > y -> b ? inf : -inf;
        else
            v1 /= (y -> m - x -> m);
        // v2 is with next
        ll v2 = (y -> b - z -> b);
        if(z -> m == y -> m)
            v2 = y -> b > z -> b ? inf : -inf;
        else
            v2 /= (z -> m - y -> m);
        return v1 >= v2;
    }
    void insert_line(ll m, ll b) {
        auto y = insert({m, b});
        y -> succ = [=] {return next (y) == end() ? 0 : &*next(y); };
        if(bad(y)) {
            erase(y);
            return;
        }
        while(next(y) != end() && bad(next(y)))
            erase(next(y));
        while(y != begin() && bad(prev(y)))
            erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((line) {x, is_query});
        return l.m * x + l.b;
    }
};
dynamic_hull cht;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int h[n], w[n];
    for(int i = 0; i < n; ++i)
        cin >> h[i];
    for(int i = 0; i < n; ++i)
        cin >> w[i];
    // we choose first and we choose last
    // the problem is we need to choose some number of pillars
    // the factors of choosing a pillar
    // height
    // cost of removing the pillar
    // use dynamic cht dp opt
    ll dp[n], pref[n];
    memset(dp, 0, sizeof(dp));
    pref[0] = 0;
    for(int i = 1; i < n; ++i)
        pref[i] = pref[i - 1] + w[i];
    cht.insert_line(2 * h[0], -sqr(h[0]));
    for(int i = 1; i < n; ++i) {
        dp[i] = -cht.eval(h[i]) + pref[i - 1] + sqr(h[i]);
        cht.insert_line(2 * h[i], -(dp[i] + sqr(h[i]) - pref[i]));
    }
    cout << dp[n - 1] << endl;
    return 0;
}