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
    int n, m;
    cin >> n >> m;
    string s[n], t[m];
    for(int i = 0; i < n; ++i)
        cin >> s[i];
    for(int i = 0; i < m; ++i)
        cin >> t[i];
    sort(t, t + m);
    for(int i = 0; i < n; ++i) {
        if(binary_search(t, t + m, s[i]))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}