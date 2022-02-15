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
        vector<int> l(3);
        bool ans = 0;
        for(int i = 0; i < 3; ++i) {
            cin >> l[i];
        }
        sort(l.begin(), l.end());
        // yang dibagi selalu yang paling besar ATAU yang paling kecil (jika l[1] == l[2])
        if((l[1] == l[2] && l[0] % 2 == 0)
        || (l[0] == l[1] && l[2] % 2 == 0)
        || (l[0] + l[1] == l[2]))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}