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
    int n, x;
    cin >> n >> x;
    int weight[n];
    for(int i = 0; i < n; ++i)
        cin >> weight[i];
    pair<int,int> best[1<<n];
    best[0] = {1,0};
    for (int s = 1; s < (1<<n); s++) {
        // initial value: n+1 rides are needed
        best[s] = {n+1,0};
        for (int p = 0; p < n; p++) {
            if (s&(1<<p)) {
                auto option = best[s^(1<<p)];
                if (option.second+weight[p] <= x) {
                    // add p to an existing ride
                    option.second += weight[p];
                } 
                else {
                    // reserve a new ride for p
                    option.first++;
                    option.second = weight[p];
                }
                best[s] = min(best[s], option);
            }
        }
    }
    cout << best[(1 << n) - 1].fi << endl;
    return 0;
}