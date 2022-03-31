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
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    map<int, int> minimum;
    for(int i = 0; i < n; ++i) {
        for(int j = 1; j <= k; ++j) {
            if(minimum[a[i] * j] == 0)
                minimum[a[i] * j] = j;
            else
                minimum[a[i] * j] = min(minimum[a[i] * j], j);
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        int ans = k + 1;
        if(minimum[x] != 0)
            ans = minimum[x];
        for(int j = 0; j < n; ++j)
            for(int l = 1; l <= 20; ++l) {
                if(minimum[x - (l * a[j])] != 0)
                ans = min(ans, l + minimum[x - (l * a[j])]);
            }
        if(ans > k)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}