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
    int n, k, d;
    cin >> n >> k >> d;
    int a[n];
    for(int i = 0; i < n; ++i)  
        cin >> a[i];
    multiset<int> tmp;
    for(int i = 0; i < k; ++i) {
        tmp.ins(a[i]);
    }
    int res = (*--tmp.end()) + *(--(--tmp.end()));
    for(int i = k; i < n; ++i) {
        tmp.erase(a[i - k]);
        tmp.ins(a[i]);
        res = max(res, (*--tmp.end()) + *(--(--tmp.end())));
    }
    cout << res << endl;
    return 0;
}