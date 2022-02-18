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
vector<int> factors[1000001];
void sieve(int limit = 1e6) {
    for(int i = 1; i <= limit; ++i) {
        for(int j = i; j <= limit; j += i)
            factors[j].pb(i);
    }
}
bool exists[(int)1e6 + 1];
int cnt[(int)1e6 + 1];
int main() {
    // observations
    // there are not going to be a lot of possible gcd states for each number
    // we only need to find whether a gcd exists or not
    // we might be able to use a trie like DP
    // which is basically dp but on prime factors?
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sieve();
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        exists[a[i]] = 1;
    }
    for(int i = 0; i < n; ++i) {
        for(auto j : factors[a[i]]) {
            ++cnt[j];
        }
    }
    int res = 0;
    // from above it
    // we don't want to propagate everything twice
    // but it is possible if there is a midpoint
    // then it can cause something wrong
    // because 
    for(int i = 1e6; i >= 1; --i) {
        //if(cnt[i] > 0)
        //    cout << i << " " << cnt[i] << endl;
        if(!exists[i] && cnt[i] > 1) {
            bool ans = 1;
            for(int j = 2 * i; j <= 1e6; j += i) {
                if(cnt[j] == cnt[i])
                    ans = 0;
            }
            if(ans)
                exists[i] = 1, ++res;
        }
    }
    cout << res << endl;
    return 0;
}