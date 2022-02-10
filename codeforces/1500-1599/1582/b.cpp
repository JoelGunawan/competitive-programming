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
        int n;
        cin >> n;
        int one_cnt = 0, zero_cnt = 0;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if(x == 1)
                ++one_cnt;
            else if(x == 0)
                ++zero_cnt;
        }
        // zero_cnt dipasangkan dengan one_cnt
        cout << (ll)pow(2, zero_cnt) * (one_cnt) << endl;
    }
    return 0;
}