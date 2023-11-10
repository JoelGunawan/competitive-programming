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
int mod = 9302023;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // coba tiap transisi dari sebelumnya, cuman hitung yg min cost
    // dp[i] = mp(min(dp[i].fi, dp[i - k].fi + 1), case hitung cost klo misal sama atau ga sama beda)
    // base transition: dp[i] = mp(dp[i - 1].fi + 1, dp[i - 1].se)
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    pair<int, ll> dp[n + 1];
    dp[0] = mp(0, 1);
    vector<string> three = {"one", "two", "six"};
    vector<string> four = {"zero", "four", "five", "nine"};
    vector<string> five = {"three", "seven", "eight"};
    for(int i = 1; i <= n; ++i) {
        dp[i] = mp(dp[i - 1].fi + 1, dp[i - 1].se);
        // coba all previous strings yg memenuhi
        if(i >= 3) {
            string pr = s.substr(i - 2, 3);
            bool trans = 0;
            for(auto j : three) {
                if(j == pr) {
                    trans = 1;
                }
            }
            if(trans) {
                if(dp[i - 3].fi + 1 < dp[i].fi) {
                    dp[i] = mp(dp[i - 3].fi + 1, dp[i - 3].se);
                }
                else if(dp[i - 3].fi + 1 == dp[i].fi) {
                    dp[i].se += dp[i - 3].se;
                }
            }
        }
        if(i >= 4) {
            string pr = s.substr(i - 3, 4);
            bool trans = 0;
            for(auto j : four) {
                if(j == pr) {
                    trans = 1;
                }
            }
            if(trans) {
                if(dp[i - 4].fi + 1 < dp[i].fi) {
                    dp[i] = mp(dp[i - 4].fi + 1, dp[i - 4].se);
                }
                else if(dp[i - 4].fi + 1 == dp[i].fi) {
                    dp[i].se += dp[i - 4].se;
                }
            }
        }
        if(i >= 5) {
            string pr = s.substr(i - 4, 5);
            bool trans = 0;
            for(auto j : five) {
                if(j == pr) {
                    trans = 1;
                }
            }
            //cout << pr << " " << trans << endl;
            if(trans) {
                if(dp[i - 5].fi + 1 < dp[i].fi) {
                    dp[i] = mp(dp[i - 5].fi + 1, dp[i - 5].se);
                }
                else if(dp[i - 5].fi + 1 == dp[i].fi) {
                    dp[i].se += dp[i - 5].se;
                }
            }
        }
        dp[i].se %= mod;
        //cout << dp[i].fi << " " << dp[i].se << endl;
    }
    cout << dp[n].fi << endl << dp[n].se << endl;
    return 0;
}