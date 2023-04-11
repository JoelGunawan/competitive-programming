#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define endl "\n"
using namespace std;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, a, b;
    cin >> n >> a >> b;
    /*
    for(int i = 1; i <= n; ++i) {
        ll l, r;
        cin >> l >> r;
        for(int j = l; j <= r; ++j) {
            cout << (j + j / b) % a << " " << j % b << endl;
        }
    }
    */
    //return 0;
    // a or b has certain pattern
    // ab -> 1 cycle, no duplikat
    // next cycle: sama persis
    // maintain cycles in terms of ab, merge all segments
    // find modulo ab
    // exist more than one cycle long -> all possible
    // size ab berarti diff >= ab - 1
    vector<pair<lll, int>> sweep;
    ll ans = -1;
    lll tot;
    if(a == b + 1)
        tot = b;
    else
        tot = (lll)a * b / gcd(a, b + 1);
    set<pair<ll, ll>> s;
    // t + floor(t/b)
    // every a * b reset (pasti)
    //for(int j = 0; j <= a * b; ++j)
    //    s.insert(make_pair((ll)(j + j / b) % a, (ll)j % b));
    //cout << s.size() << " " << (ll)tot << endl;
    for(int i = 1; i <= n; ++i) {
        ll l, r;
        cin >> l >> r;
        if(r - l >= tot - 1) {
            ans = tot;
        }
        else {
            if(tot <= 1e18) {
                l = (l % tot);
                r = (r % tot);
            }
            if(l <= r) {
                sweep.push_back(make_pair(l, 0));
                sweep.push_back(make_pair(r, 1));
            }
            else {
                sweep.push_back(make_pair(l, 0));
                sweep.push_back(make_pair(tot - 1, 1));
                sweep.push_back(make_pair(0, 0));
                sweep.push_back(make_pair(r, 1));
            }
        }
    }
    if(ans != -1)
        cout << ans << endl, exit(0);
    sort(sweep.begin(), sweep.end());
    int cnt = 0;
    ll st = -5;
    ans = 0;
    for(auto i : sweep) {
        if(i.second) {
            // end
            --cnt;
            if(cnt == 0)
                ans += i.first - st;
        }
        else {
            // start
            // start itu + cnt
            // set start kalo belum di set
            if(cnt == 0)
                st = i.first - 1;
            ++cnt;
        }
    }
    cout << ans << endl;
}