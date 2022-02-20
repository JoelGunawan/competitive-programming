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
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> x, y;
    x.pb(0), y.pb(0);
    vector<int> next[n + 1];
    for(int i = 0; i < n; ++i)
        next[a[i]].pb(i);
    for(int i = 0; i <= n; ++i)
        next[i].pb(n);
    for(int i = 0; i < n; ++i) {
        //cout << x.back() << " " << y.back() << endl;
        //cout << flush;
        int tmp1 = *upper_bound(next[x.back()].begin(), next[x.back()].end(), i),
        tmp2 = *upper_bound(next[y.back()].begin(), next[y.back()].end(), i);
        //cout << x.back() << " " << y.back() << " " << tmp1 << " " << tmp2 << endl;
        if(a[i] != x.back() && (tmp1 < tmp2 || a[i] == y.back()))
            x.pb(a[i]);
        else if(a[i] != y.back())
            y.pb(a[i]);
        //cout << x.size() << " " << y.size() << endl;
    }
    //cout << x.size() << " " << y.size() << endl;
    cout << x.size() + y.size() - 2 << endl;
    return 0;
}