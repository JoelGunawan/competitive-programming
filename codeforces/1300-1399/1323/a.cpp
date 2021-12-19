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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        if(n == 1 && (a[0] & 1)) {
            cout << -1 << endl;
            continue;
        }
        if(a[0] % 2 == 0)
            cout << 1 << endl << 1 << endl;
        else if(a[1] % 2 == 0)
            cout << 1 << endl << 2 << endl;
        else
            cout << 2 << endl << 1 << " " << 2 << endl;
    }
    return 0;
}