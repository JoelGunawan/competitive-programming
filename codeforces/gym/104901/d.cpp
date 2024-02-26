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
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(r1 - l1 > 9 || r2 - l2 > 9) {
            cout << 9 << endl;
        }
        else {
            int mx = 0;
            for(int i = l1; i <= r1; ++i) {
                for(int j = l2; j <= r2; ++j) {
                    string s = to_string(i + j);
                    for(auto j : s) {
                        mx = max(mx, j - '0');
                    }
                }
            }
            cout << mx << endl;
        }
    }
    return 0;
}