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
    pair<int, int> a[m];
    int total_sum = 0;
    for(int i = 0; i < m; ++i) {
        int l;
        cin >> l;
        a[i] = mp(l, i);
        total_sum += l;
    }
    int ans[m];
    memset(ans, -1, sizeof(ans));
    if(total_sum < n) {
        cout << -1 << endl;
        exit(0);
    }
    sort(a, a + m);
    reverse(a, a + m);
    int minimum = 1, maximum = 1;
    for(int i = 0; i < m; ++i) {
        // choose between minimum and maximum
        // it is always possible
        // choose minimum start_idx that still satisfies
        int new_min = minimum + 1, new_max = maximum + 1;
        
    }
    return 0;
}