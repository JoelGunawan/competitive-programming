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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> g, l;
    for(int i = 0; i < n; ++i) {
        char a; int x;
        cin >> a >> x;
        if(a == 'G')
            g.pb(x);
        else    
            l.pb(x);
    }
    sort(l.begin(), l.end());
    sort(g.begin(), g.end());
    // for each G[i] pick all L[i] > G[i]
    int res = max(res, max((int)l.size(), (int)g.size()));
    for(int i = 0; i < g.size(); ++i) {
        res = max(res, i + 1 + (int)(l.end() - lower_bound(l.begin(), l.end(), g[i])));
    }
    cout << n - res << endl;
    return 0;
}