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
    int n, x, y;
    cin >> n >> x >> y;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    // there are 3 types of index
    // neutral
    // min/max index
    // bad index
    // we have to select a range such that we select a min/max index
    // for each index, check r
    // maintain closest bad index
    // if current is min, maintain closest right max index
    // if current is max, maintain closest right min index
    // ez pz
    int closest_bad[n], closest_min[n], closest_max[n], last_bad = n, last_min = n, last_max = n;
    memset(closest_bad, -1, sizeof(closest_bad));
    ll res = 0;
    for(int i = n - 1; i >= 0; --i) {
        if(a[i] > x || a[i] < y)
            last_bad = i;
        if(a[i] == x)
            last_max = i;
        if(a[i] == y)
            last_min = i;
        // calc res
        if(max(last_max, last_min) < last_bad) {
            res += last_bad - max(last_max, last_min);
        }
    }
    cout << res << endl;
    return 0;
}