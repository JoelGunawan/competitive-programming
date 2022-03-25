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
int get_dist(char a, char b) {
    //cout << a << " " << b << " " << min(26 - (max(a, b) - min(a, b)), max(a, b) - min(a, b)) << endl;
    return min(26 - (max(a, b) - min(a, b)), max(a, b) - min(a, b));
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // tiap indeks harus sama dengan beberapa syarat
    // syarat 1 -> sama dengan kanannya
    // syarat 2 -> sama dengan bawahnya
    // syarat 3 -> sama dengan diagonal kanan bawahnya
    // try each ascii char and find distance to such char
    int n, m;
    cin >> n >> m;
    char a[n][m];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    ll res = 0;
    for(int i = 0; i < n / 2 + n % 2; ++i) {
        for(int j = 0; j < m / 2 + m % 2; ++j) {
            // get unique pairs using set easily
            set<pair<int, int>> s;
            s.ins(mp(i, j));
            s.ins(mp(n - i - 1, j));
            s.ins(mp(i, m - j - 1));
            s.ins(mp(n - i - 1, m - j - 1));
            // now compare all in s and try to get min
            // brute force every char
            int tmp = INT_MAX;
            for(char k = 'A'; k <= 'Z'; ++k) {
                int tmp2 = 0;
                for(auto i : s)
                    tmp2 += get_dist(a[i.fi][i.se], k);
                tmp = min(tmp, tmp2);
            }
            //cout << i << " " << j << " " << tmp << endl;
            res += tmp;
        }
    }
    cout << res << endl;
    return 0;
}