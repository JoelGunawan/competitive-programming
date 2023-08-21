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
    int n, k;
    cin >> n >> k;
    int c[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> c[i];
    sort(c + 1, c + n + 1);
    reverse(c + 1, c + n + 1);
    // nanti di lakuin dr paling belakang, terus first instance dimana dia negative, berarti dia distrib ke banyak
    // terus nnti habis di distrib ke banyak di jalanin
    ll res = 0, cur = 0;
    int idx = 0;
    bool pos = 1;
    ll group[k + 1];
    memset(group, 0, sizeof(group));
    for(int i = 1; i <= n; ++i) {
        if(pos) {
            res += cur;
            cur += c[i];
            if(cur < 0) {
                pos = 0;
                group[idx++] = cur;
                if(idx > k)
                    idx = 0;
                //cout << i << endl;
            }
        }   
        else {
            res += group[idx];
            group[idx++] += c[i];
            if(idx > k)   
                idx = 0;
        }
    }
    cout << res << endl;
    return 0;
}