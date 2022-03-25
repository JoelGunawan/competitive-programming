// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
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
ll inf = 5e10;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);
    ll n;
    cin >> n;
    // go from back to front
    // since a guy in front will NEVER block the guy in the back
    ll a[n];
    ll delay[n];
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    reverse(a, a + n);  
    // we maintain active segments
    // and each time we move forward we increase everything in the segment by 1
    // we check what time can we insert the passenger by having segments of time
    // fi is r, se is l
    set<pair<ll, ll>> s;
    s.ins(mp(a[0], a[0]));
    memset(delay, 0, sizeof(delay));
    for(ll i = 1; i < n; ++i) {
        ll tmp = a[i] - i;
        //cout << tmp << endl;
        if(s.lb(mp(tmp, -inf)) == s.end() || (*s.lb(mp(tmp, -inf))).se > tmp) {
            //cout << "TEST1" << endl;
            s.ins(mp(tmp, tmp));
            auto cur = s.find(mp(tmp, tmp)), next = cur;
            ++next;
            // clean next
            if(next != s.end() && (*next).se == (*cur).fi + 1) {
                s.ins(mp((*next).fi, (*cur).se));
                auto tmp = cur, tmp2 = next;
                ++tmp2;
                tmp = s.find(mp((*next).fi, (*cur).se));
                s.erase(cur);
                s.erase(next);
                cur = tmp, next = tmp2;
            }
            // clean prev
            auto prev = cur;
            --prev;
            if(cur != s.begin() && (*prev).fi + 1 == (*cur).se) {
                s.ins(mp((*cur).fi, (*prev).se));
                s.erase(prev);
                s.erase(cur);
            }
        }
        else {
            //cout << "TEST2" << endl;
            auto temporary = s.lb(mp(tmp, -inf));
            delay[i] = (*temporary).fi + 1 - tmp;
            s.ins(mp((*temporary).fi + 1, (*temporary).se));
            auto cur = s.find(mp((*temporary).fi + 1, (*temporary).se));
            s.erase(temporary);
            auto next = cur;
            ++next;
            if(next != s.end() && (*next).se == (*cur).fi + 1) {
                s.ins(mp((*next).fi, (*cur).se));
                s.erase(cur);
                s.erase(next);
            }
            //cout << tmp << endl;
            //for(auto i : s) {
            //    std::cout << i.se << " " << i.fi << endl;
            //}
            //std::cout << endl;
        }
    }
    ll res = 0;
    for(ll i = 0; i < n; ++i) {
        //std::cout << delay[i] << " ";
        res = max(res, (n - i) + a[i] + 1 + delay[i]);
    }
    //std::cout << endl;
    std::cout << res << endl;
    return 0;
}