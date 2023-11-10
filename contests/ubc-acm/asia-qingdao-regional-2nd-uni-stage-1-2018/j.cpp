// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
void tc() {
    ll a, b, c, d, v, t;
    cin >> a >> b >> c >> d >> v >> t;
    // find all points where ka - lc <= t
    ll over = t % lcm(a, c);
    // every a * c, can just count as 1 time
    ll tot = b + d - 1, overcnt = b + d - 1;
    if(min(a, c) <= v)
        ++tot;
    ll cv = 0, cur = 0;
    ll cons = lcm(a, c) / c;
    for(int i = 1; i < cons; ++i) {
        // cur is ic
        cur += c;
        ll add;
        while(cv + a <= cur)
            cv += a;
        if(min(c, cur - cv) <= v) {
            add = d;
        } 
        else
            add = d - 1;
        //cout << add << " ";
        //cout << cur << " " << add << endl;
        tot += add;
        if(cur <= over)
            overcnt += add;
    }
    cv = 0, cur = 0;
    //cout << endl;
    cons = lcm(a, c) / a;
    for(int i = 1; i < cons; ++i) {
        // cur is ia
        cur += a;
        ll add;
        while(cv + c <= cur)
            cv += c;
        if(min(cur - cv, a) <= v) {
            add = b;
        } 
        else
            add = b - 1;
        //cout << cur << " " << add << endl;
        //cout << add << " ";
        tot += add;
        if(cur <= over)
            overcnt += add;
    }
    //cout << endl;
    //cout << tot << " " << overcnt << endl;
    cout << overcnt + t / lcm(a, c) * tot << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}