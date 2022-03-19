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
ll mod[3] = {1e9 + 7, 1e9 + 9, 998244353};
ll key[2] = {1234567, 2345678};
ll powmod(ll a, ll b, ll mod) {
    if(b == 0)
        return 1 % mod;
    else {
        ll tmp = powmod(a, b >> 1, mod);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
void tc() {
    int n;
    cin >> n;
    
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