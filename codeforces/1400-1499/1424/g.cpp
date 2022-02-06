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
    pair<int, bool> a[2 * n];
    for(int i = 0; i < n; ++i) {
        int b, d;
        cin >> b >> d;
        a[2 * i] = mp(b, 1);
        a[2 * i + 1] = mp(d, 0);
    }
    sort(a, a + 2 * n);
    int active = 0, res = 0, res_year;
    for(int i = 0; i < 2 * n; ++i) {
        if(!a[i].se)
            --active;
        else
            ++active;
        if(active > res) {
            res = active;
            res_year = a[i].fi;
        }
    }
    cout << res_year << " " << res << endl;
    return 0;
}