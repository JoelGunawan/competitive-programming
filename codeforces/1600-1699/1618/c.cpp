#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ll long long
#define lll __int128
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
using namespace std;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
void tc() {
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    ll odd_gcd = 0, even_gcd = 0;
    for(int i = 0; i < n; ++i) {
        if(i & 1)
            odd_gcd = gcd(odd_gcd, a[i]);
        else
            even_gcd = gcd(even_gcd, a[i]);
    }
    // no odd index is divisible by even gcd or no even index is divisble by odd gcd
    bool even_ans = 1, odd_ans = 1;
    for(int i = 0; i < n; ++i) {
        if((i & 1) && a[i] % even_gcd == 0)
            even_ans = 0;
        if(!(i & 1) && a[i] % odd_gcd == 0)
            odd_ans = 0;
    }
    if(even_ans)
        cout << even_gcd << endl;
    else if(odd_ans)
        cout << odd_gcd << endl;
    else
        cout << 0 << endl;
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