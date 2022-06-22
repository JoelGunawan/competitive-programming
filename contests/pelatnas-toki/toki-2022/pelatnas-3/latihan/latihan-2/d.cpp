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
int mod1 = 1e9 + 7, mod2 = 1e9 + 9;
ll powmod(ll a, ll b, ll mod) {
    if(b == 0)
        return 1 % mod;
    else {
        ll tmp = powmod(a, b >> 1, mod);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
struct hashing {
    string s;
    pair<vector<int>, vector<int>> h;
    void get_hash() {
        
    }
    pair<int, int> query(int l, int r) {

    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c; string s;
    cin >> a >> b >> c >> s;
    hashing t;
    t.s = s;

    return 0;
}