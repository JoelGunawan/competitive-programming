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
    // two sum with shit input
    vector<int> a;
    int x;
    while(cin >> x)
        a.push_back(x);
    for(int i = 0; i < a.size() - 1; ++i) {
        for(int j = i + 1; j < a.size()- 1; ++j) {
            if(a[i] + a[j] == a.back()) {
                cout << "true" << endl;
                return 0;
            }
        }
    }
    cout << "false" << endl;
    return 0;
}