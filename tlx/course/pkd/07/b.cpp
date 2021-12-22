// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
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
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    pair<int, int> a[k + 1];
    for(int i = 1; i <= k; ++i) {
        int w, h;
        cin >> w >> h;
        a[i] = mp(w, h);
    }
    pair<int, vector<int>> knapsack[2][n + 1];
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j <= n; ++j) {
            knapsack[i][j] = mp(0, vector<int>());
        }
    }
    for(int i = 1; i <= k; ++i) {
        for(int j = 0; j <= n; ++j)
            knapsack[i % 2][j] = knapsack[(i + 1) % 2][j];
        for(int j = a[i].fi; j <= n; ++j) {
            if(knapsack[(i + 1) % 2][j - a[i].fi].fi + a[i].se > knapsack[i % 2][j].fi) {
                knapsack[i % 2][j].fi = knapsack[(i + 1) % 2][j - a[i].fi].fi + a[i].se;
                knapsack[i % 2][j].se = knapsack[(i + 1) % 2][j - a[i].fi].se;
                knapsack[i % 2][j].se.pb(i);
            }
            else if(knapsack[(i + 1) % 2][j - a[i].fi].fi + a[i].se == knapsack[i % 2][j].fi) {
                vector<int> tmp = knapsack[(i + 1) % 2][j - a[i].fi].se;
                tmp.pb(i);
                if(tmp < knapsack[i % 2][j].se)
                    knapsack[i % 2][j].se = tmp;
            }
        }
    }
    int tmp = n;
    while(tmp > 0 && knapsack[k % 2][tmp].fi == knapsack[k % 2][tmp - 1].fi)
        --tmp;
    for(int i = 0; i < knapsack[k % 2][tmp].se.size(); ++i) {
        cout << knapsack[k % 2][tmp].se[i] << endl;
    }
    return 0;
}