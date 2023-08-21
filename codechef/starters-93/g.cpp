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
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if(k & 1) {
            if(n & 1)
                cout << "Shivansh" << endl;
            else
                cout << "Tina" << endl;
        }
        else {
            int tmp = n % (k + 1);
            if(tmp % 2 == 0 && tmp != k)
                cout << "Tina" << endl;
            else
                cout << "Shivansh" << endl;
        }
        /*
        bool dp[n + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= i; j *= k) {
                if(i >= j && !dp[i - j])
                    dp[i] = 1;
            }
        }
        for(int i = 0; i <= n; ++i) {
            cout << i << " " << dp[i] << endl;
        }
        cout << endl;
        for(int i = 0; i <= n; ++i) {
            if(!dp[i])
                cout << i << " ";
        }
        cout << endl;
        */
    }
    return 0;
}