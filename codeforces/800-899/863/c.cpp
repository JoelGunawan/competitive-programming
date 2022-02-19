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
int f(pair<int, int> x) {
    int a = x.fi, b = x.se;
    if(a == b)
        return 0;
    if(a == b + 1)
        return 1;
    else if(a == 1 && b == 3)
        return 1;
    else
        return -1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll k; int inita, initb;
    cin >> k >> inita >> initb;
    int a[3][3], b[3][3];
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            cin >> a[i][j];
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            cin >> b[i][j];
    
    vector<pair<int, int>> previous;
    previous.pb(mp(inita, initb));
    pair<int, int> cur;
    while(true) {       
        cur = previous.back();
        cur = mp(a[cur.fi - 1][cur.se - 1], b[cur.fi - 1][cur.se - 1]);
        //cout << cur.fi << " " << cur.se << endl;
        previous.pb(cur);
        bool found = 0;
        for(int i = 0; i < previous.size() - 1; ++i)
            if(previous[i] == cur)
                found = 1;
        if(found)
            break;
    }
    vector<pair<int, int>> loop;
    vector<pair<int, int>> not_loop;
    int start_idx;
    for(int i = 0; i < previous.size(); ++i)
        if(previous[i] == cur) {
            start_idx = i;
            break;
        }
    for(int i = start_idx; i < previous.size() - 1; ++i)
        loop.pb(previous[i]);
    for(int i = 0; i < start_idx; ++i)  
        not_loop.pb(previous[i]);
    ll alice = 0, bob = 0;
    while(k && not_loop.size()) {
        if(f(not_loop.front()) == -1)
            ++bob;
        else if(f(not_loop.front()) == 1)
            ++alice;
        //else
        //    cout << "TEST" << endl;
        not_loop.erase(not_loop.begin());
        --k;
    }
    pair<int, int> prefix[loop.size() + 1];
    prefix[0] = mp(0, 0);
    for(int i = 1; i <= loop.size(); ++i) {
        prefix[i] = prefix[i - 1];
        if(f(loop[i - 1]) == 1)
            ++prefix[i].fi;
        else if(f(loop[i - 1]) == -1)
            ++prefix[i].se;
        //else
        //    cout << "TEST2" << endl;
    }
    //cout << k << " " << loop.size() << " " << prefix[loop.size()].fi << " " << prefix[loop.size()].se << endl;
    alice += k / loop.size() * prefix[loop.size()].fi + prefix[k % loop.size()].fi;
    bob += k / loop.size() * prefix[loop.size()].se + prefix[k % loop.size()].se;
    cout << alice << " " << bob << endl;
    return 0;
}