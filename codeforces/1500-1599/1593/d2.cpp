// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
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
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        // find maximum gcd of the differences between the numbers
        // select at least half of the numbers
        // abritrarily large -> all the same
        // else we can brute force every difference?
        // where the numbers is a difference
        // then we can try to scale it
        // find a sequence of numbers such that all the numbers % k is the same
        // find all differences between pairs
        // find all factors of the differences
        // and brute force all factors
        set<int> factors;
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j) {
                int cur = abs(a[j] - a[i]);
                for(int k = 1; k <= sqrt(cur); ++k)
                    if(cur % k == 0)
                        factors.ins(k), factors.ins(cur / k);
            }
        map<int, int> cnt;
        int res = 1;
        for(auto factor : factors) {
            //cout << factor << endl;
            for(int i = 0; i < n; ++i) {
                //cout << ((a[i] % factor) + factor) % factor << " ";
                ++cnt[((a[i] % factor) + factor) % factor];
            }
            //cout << endl;
            for(auto i : cnt)
                if(i.se >= n / 2) {
                    res = max(res, factor);
                }
            cnt.clear();
        }
        // check for -1
        for(int i = 0; i < n; ++i) {
            ++cnt[a[i]];
            if(cnt[a[i]] >= n / 2)
                res = -1;
        }
        cout << res << endl;
    }
    return 0;
}