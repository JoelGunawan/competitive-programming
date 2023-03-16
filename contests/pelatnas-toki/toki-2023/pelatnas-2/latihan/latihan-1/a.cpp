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
    // pakai approach x2 atau +1
    // harusnya cukup
    // make k into binary
    int k;
    cin >> k;
    vector<int> bin;
    for(int i = 0; i < 20; ++i) {
        if((1 << i) & k)
            bin.pb(1);
        else
            bin.pb(0);
    }
    while(bin.back() == 0)
        bin.pop_back();
    // bin.size() - 1, buat "manual"
    if(k == 1) {
        cout << "2 1" << endl;
        cout << "1 2" << endl;
        return 0;
    }
    // buat pola, nanti 4, 6, 8, 10, 12, ...
    int mx = 2;
    reverse(bin.begin(), bin.end());
    int tmp = 100;
    int last = 1;
    vector<pair<int, int>> edges;
    for(int i = 1; i < bin.size(); ++i) {
        // buat path 2 * i + 1 ke 2 * i + 1
        // 3 -> 4
        // 1 -> 4
        // 1 -> 3
        edges.push_back(mp(2 * i + 1, 2 * i + 2));
        edges.push_back(mp(last, 2 * i + 1));
        edges.push_back(mp(last, 2 * i + 2));
        if(bin[i]) {
            edges.push_back(mp(1, tmp));
            edges.push_back(mp(tmp--, 2 * i + 2));
        }
        last = 2 * i + 2;
    }
    edges.push_back(mp(last, 2));
    cout << 100 << " " << edges.size() << endl;
    for(auto i : edges)
        cout << i.fi << " " << i.se << endl;
    return 0;
}