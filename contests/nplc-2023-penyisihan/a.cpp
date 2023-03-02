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
    vector<int> a;
    int x, sum = 0;
    while(cin >> x)
        a.pb(x), sum += x;
    if(sum % 3) {
        cout << "false" << endl;
        return 0;
    }
    int i_idx = -1, cum = 0;
    for(int i = 0; i < a.size(); ++i) {
        cum += a[i];
        if(cum == sum / 3) {
            i_idx = i;
            break;
        }
    }
    if(i_idx == -1) {
        cout << "false" << endl;
        return 0;
    }
    cum = 0; int j_idx = -1;
    for(int i = i_idx + 1; i < a.size(); ++i) {
        cum += a[i];
        if(cum == sum / 3) {
            j_idx = i;
            break;
        }
    }
    if(j_idx == -1)
        cout << "false" << endl;
    else
        cout << "true" << endl;
    return 0;
}