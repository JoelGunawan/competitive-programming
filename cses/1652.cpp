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
    int n, q;
    cin >> n >> q;
    char arr[n][n];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> arr[i][j];
    int pref[n + 1][n + 1];
    memset(pref, 0, sizeof(pref));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            if(arr[i - 1][j - 1] == '*')
                ++pref[i][j];
            //cout << pref[i][j] << " ";
        }
        //cout << endl;
    }
    for(int i = 0; i < q; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << pref[c][d] - pref[a - 1][d] - pref[c][b - 1] + pref[a - 1][b - 1] << endl;
    }
    return 0;
}