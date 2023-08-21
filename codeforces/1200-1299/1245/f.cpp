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
        int l, r;
        cin >> l >> r;
        ll res = 0;
        if(l == 0 && r == 0) {
            cout << 1 << endl;
            continue;
        }
        else if(l == 0) {
            res += r - l + 1;
            ++l;
        }
        // how many pairs yg bs dr sebuah K
        // observe pattern dmn sum bs sama dengan L
        // given an upper bound, every bit below that can be either on or off 
        // set lower bound -> harus ada mandatory on/off
        // jadi dp bit, cari tiap bit ada on/offnya berapa, nnti cri yg on ada mis. 5, itu ada berapa cara yg valid
        // dp[30][30]
        // 0 -> ikut atas
        // 1 -> udah bebas
        // 2 -> ikut bawah
        // 3 -> special state, atas dan bawah
        // state 1 -> pos yg udh di consider (dr besar ke kecil aja)
        // state 2 -> pos yg udh on
        ll dp[32][32][4];
        memset(dp, 0, sizeof(dp));
        dp[30][0][3] = 1;
        int tmp1 = 0, start_idx = -1;
        for(int i = 29; i >= 0; --i) {
            if((1 << i) & l == (1 << i) & r) {
                int tmp2 = tmp1 + (bool)((1 << i) & l);
                dp[i][tmp2][3] = dp[i + 1][tmp1][3];
                tmp1 = tmp2;
            }
            else {
                start_idx = i;
                break;
            }
        }
        for(int i = start_idx; i >= 0; --i) {
            for(int j = 0; j <= 30; ++j) {
                // transisi bebas
                // case transisi dari sebelumnya yg sudah bebas
                dp[i][j][1] += (j > 0 ? dp[i + 1][j - 1][1] : 0) + dp[i + 1][j][1];
                // case transisi dari sebelumnya yg ikut bawah
                dp[i][j][1] += (j > 0 && (1 << i) & l != 1 << i) ? dp[i + 1][j - 1][2] : 0; 
                // case transisi dari sebelumnya yg ikut atas
                dp[i][j][1] += (((1 << i) & r) == (1 << i)) ? dp[i + 1][j][0] : 0;
                // transisi ikut bawah
                // dr tetep ikut bawah
                dp[i][j][2] += (j - (bool)((1 << i) == (1 << i) & l)) >= 0 ? dp[i + 1][j - (bool)((1 << i) == (1 << i) & l)][2] : 0;
                // dr special case
                // krn selalu akan 0, jadi biarin g ush tambah
                dp[i][j][2] += dp[i + 1][j][3];
                // transisi ikut atas
                // dr tetep ikut atas,
                dp[i][j][0] += (j - (bool)((1 << i) == (1 << i) & l)) >= 0 ? dp[i + 1][j - (bool)((1 << i) == (1 << i) & l)][0] : 0;
                dp[i][j][0] += j > 0 ? dp[i + 1][j - 1][3] : 0;
            }
        }
        ll pow2[31];
        pow2[0] = 1;
        for(int i = 1; i <= 30; ++i)   
            pow2[i] = pow2[i - 1] * 2;
        for(int i = 0; i <= 30; ++i) {
            for(int j = 0; j < 4; ++j) {
                res += dp[0][i][j] * pow2[i];
            }
        }
        cout << res << endl;
    }
    return 0;
}