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
    int t;
    cin >> t;
    while(t--) {
        ll n, x, y;
        cin >> n >> x >> y;
        ll a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        int parity = 0;
        for(int i = 0; i < n; ++i) 
            parity += (a[i] & 1);
        if(parity % 2 == abs(y - x) % 2)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
    return 0;
}