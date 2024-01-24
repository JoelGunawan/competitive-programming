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
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n + 1];
        bool zero = 0;
        int cnt_neg = 0;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            if(a[i] == 0)
                zero = 1;
            if(a[i] < 0)
                ++cnt_neg;
        }
        if(zero || (cnt_neg & 1)) {
            cout << 0 << endl;
        }
        else {
            cout << 1 << endl;
            cout << 1 << " " << 0 << endl;
        }
    }
    return 0;
}