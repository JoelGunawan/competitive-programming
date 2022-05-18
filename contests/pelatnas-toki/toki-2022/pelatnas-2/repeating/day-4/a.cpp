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
#define ld long double
using namespace std;
bool comp(string a, string b) {
    // based on last occurence of '*'
    for(int i = a.size() - 1; i >= 0; --i) {
        if(a[i] == b[i])    
            continue;
        else
            return a[i] > b[i];
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // buat paling mendekati kiri atas
    // sort strings
    // O(nm^2logm)
    // terus cari siklus manual
    // O(n^2m)
    int n, m;
    cin >> n >> m;
    string a[n][m], b[n * m];
    for(int i = 0; i < n; ++i)
        cin >> a[i][0];
    for(int i = 0; i < n; ++i) {
        for(int j = 1; j < m; ++j) {
            string tmp = "";
            for(int k = 0; k < m; ++k) {
                tmp += a[i][0][(j + k) % m];
            }
            a[i][j] = tmp;
        }
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) {
            b[i * m + j] = a[i][j];
        }
    sort(b, b + n * m, comp);
    int values[n][m];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            values[i][j] = lower_bound(b, b + n * m, a[i][j], comp) - b;
        }
    }
    // first is original index and se is cycle
    // remember: cari dari bawah ke atas
    pair<vector<int>, pair<int, int>> ans[n * m];
    cout << endl;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            vector<int> tmp;
            for(int k = 0; k < n; ++k) {
                tmp.pb(values[(i - k + n) % n][j]);
            }
            ans[i * m + j] = mp(tmp , mp(i, j));
        }
    }
    sort(ans, ans + n * m);
    //for(int i = 0; i < n; ++i) {
    //    cout << ans[0].fi[i] << endl;
    //}
    for(int i = 0; i < n; ++i) {
        //cout << ans[0].se.fi << " " << ans[0].se.se << endl;
        cout << a[(i + ans[0].se.fi + 1) % n][ans[0].se.se] << endl;
    }
    return 0;
}