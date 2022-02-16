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
    map<int, ll> one, two;
    int n, k;
    cin >> n >> k;
    ll res = 0;
    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if(a % k == 0) {
            res += two[a / k];
            two[a] += one[a / k];
        }
        ++one[a];
    }
    cout << res << endl;
    return 0;
}