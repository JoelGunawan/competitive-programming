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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int p[n];
    for(int i = 0; i < n; ++i) {
        cin >> p[i];
    }   
    // longest directly increasing sequence
    int size[n + 1];
    memset(size, 0, sizeof(size));
    for(int i = 0; i < n; ++i) {
        size[p[i]] = size[p[i] - 1] + 1;
    }
    int m = 0;
    for(int i = 0; i <= n; ++i)
        m = max(m, size[i]);
    cout << n - m << endl;
    return 0;
}