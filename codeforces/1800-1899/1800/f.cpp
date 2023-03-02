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
    // inverse mask, kecuali 1
    // yang 1 itu, nanti harus di cek jumlahnya zero atau ngga
    // tiap mask maintain count of zero in each zero index
    int n;
    cin >> n;
    string a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    // fi -> mask, se -> di index itu zero atau ngga
    map<int, vector<int>> m;
    ll res = 0;
    for(int i = 0; i < n; ++i) {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for(auto j : a[i])
            ++cnt[j - 'a'];
        int mask = 0, inv = 0;
        for(int j = 0; j < 26; ++j) {
            mask += (cnt[j] & 1) << j;
            inv += (!(cnt[j] & 1)) << j;
        }
        //cout << mask << " " << inv << endl;
        for(int j = 0; j < 26; ++j) {
            if(!((1 << j) & mask) && cnt[j] == 0) {
                // find inverse mask
                int tmp = inv ^ (1 << j);
                //cout << "QUERY " << tmp << " " << j << endl;
                if(m[tmp].size()) {
                    res += m[tmp][j];
                }
            }
        }
        for(int j = 0; j < 26; ++j) {
            if(cnt[j] == 0) {
                if(m[mask].size()) {
                    ++m[mask][j];
                }
                else {
                    vector<int> tmp = vector<int>(26, 0);
                    ++tmp[j];
                    m[mask] = tmp;
                }
                //cout << j << " ";
            }
        }
        //cout << endl;
    }
    cout << res << endl;
    return 0;
}