// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int pr[10][(int)1e6 + 5], num[(int)1e6 + 5];
    memset(pr, 0, sizeof(pr));
    for(int i = 0; i <= 1e6; ++i) {
        if(i < 10)
            num[i] = i;
        else {
            int tmp = i, res = 1;
            while(tmp) {
                if(tmp % 10 != 0)
                    res *= tmp % 10;
                tmp /= 10;
            }
            num[i] = num[res];
        }
    }
    for(int i = 1; i <= 1e6; ++i) {
        for(int j = 0; j < 10; ++j) {
            pr[j][i] = pr[j][i - 1];
        }
        ++pr[num[i]][i];
    }
    int q;
    cin >> q;
    while(q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << pr[k][r] - pr[k][l - 1] << endl;
    }
    return 0;
}