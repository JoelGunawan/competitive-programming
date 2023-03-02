// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int cnt[(int)2e5 + 5];
    memset(cnt, 0, sizeof(cnt));
    int pref_gcd[n + 2], suff_gcd[n + 2];
    pref_gcd[0] = 0, suff_gcd[n + 1] = 0;
    for(int i = 1; i <= n; ++i) {
        pref_gcd[i] = gcd(pref_gcd[i - 1], a[i]);
    }
    for(int i = n; i >= 1; --i) {
        suff_gcd[i] = gcd(suff_gcd[i + 1], a[i]);
    }
    for(int i = 1; i <= n; ++i) {
        int tmp = gcd(pref_gcd[i - 1], suff_gcd[i + 1]);
        for(int j = 2; j <= sqrt(tmp); ++j) {
            if(tmp % j == 0) {
                int pwr = 0;
                while(tmp % j == 0)
                    ++pwr, tmp /= j;
                cnt[j] = max(cnt[j], pwr);
            }
        }
        if(tmp > 1)
            cnt[tmp] = max(cnt[tmp], 1);
    }
    ll res = 1;
    for(int i = 1; i <= 2e5; ++i) {
        for(int j = 0; j < cnt[i]; ++j) {
            res *= i;
        }
    }   
    cout << res << endl;
    return 0;
}