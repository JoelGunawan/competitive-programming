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
ll exp(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = exp(a, b >> 1);
        tmp = (tmp * tmp);
        return b & 1 ? (tmp * a) : tmp;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // dp based on unique score count
    // dp[cnt][unique_cnt]
    // 2 -> 2
    // 3 -> 4
    // 4 -> 1 2 3 4, 1 2 3 3, 1 2 2 2, 1 1 1 1, 1 1 3 4, 1 2 2 4, 1 1 1 4, 1 1 3 3 -> 8
    // each student in a ranking has 2 possibilities
    // same score as prev
    // lower score than prev
    // 2^n
    int n;
    cin >> n;
    cout << exp(2, n - 1) << endl;
    return 0;
}