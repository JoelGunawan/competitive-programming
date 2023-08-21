// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int lim = 3e5 + 5;
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
    // cari lowest depth yg masih ada isinya, terus pelan" mulai habisin isinya ke arah bawah sampe udah bener
    // total kompleksitasnya O(NlogN)
    int q;
    int cost[lim], gold[lim], par[19][lim];
    memset(cost, -1, sizeof(cost));
    memset(gold, -1, sizeof(gold));
    memset(par, -1, sizeof(par));
    cin >> q >> gold[0] >> cost[0];
    for(int i = 1; i <= q; ++i) {
        int t;
        cin >> t;
        if(t == 1) {
            int p, a, c;
            cin >> p >> a >> c;
            par[0][i] = p;
            gold[i] = a;
            cost[i] = c;
            for(int j = 1; j < 19; ++j) {
                if(par[j - 1][i] != -1)
                    par[j][i] = par[j - 1][par[j - 1][i]];
            }
        }
        else {
            int v, w;
            cin >> v >> w;
            // cari first parent yg goldnya non zero
            if(gold[v] == 0) {
                cout << "0 0" << endl;
                continue;
            }           
            // else berarti cari index yg bs
            ll cur_taken = 0, cur_cost = 0;
            while(gold[v] && cur_taken < w) {
                int st = v;
                for(int j = 18; j >= 0; --j) {
                    if(par[j][st] != -1 && gold[par[j][st]] != 0)
                        st = par[j][st];
                }
                // st -> index dgn lowest depth yg non zero gold
                if(gold[st] > w - cur_taken) {
                    cur_cost += 1ll * (w - cur_taken) * cost[st];
                    gold[st] -= w - cur_taken;
                    cur_taken += w - cur_taken;
                }
                else {
                    // take all gold
                    cur_cost += 1ll * gold[st] * cost[st];
                    cur_taken += gold[st];
                    gold[st] = 0;
                }
            }
            cout << cur_taken << " " << cur_cost << endl;
        }
    }
    return 0;
}