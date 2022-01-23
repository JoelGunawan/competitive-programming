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
void tc() {
    int n;
    cin >> n;
    int a[n];
    // find longest arithmetic sequence
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int res = 0;
    map<pair<int, double>, int> ar;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            double diff = 1.0 * (a[i] - a[j]) / (i - j);
            ar[mp(i, diff)] = max(ar[mp(i, diff)], ar[mp(j, diff)] + 1);
            res = max(res, ar[mp(i, diff)]);
        }
    }
    cout << n - res - 1 << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
    return 0;
}