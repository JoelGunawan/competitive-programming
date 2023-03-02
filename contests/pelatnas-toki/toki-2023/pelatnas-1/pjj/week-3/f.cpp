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
int n;
pair<int, int> a[16];
bool used[16];
int sqr(int a) {
    return a * a;
}
double generate(int idx, double cur_dist) {
    if(idx == n)
        return cur_dist;
    else {
        // find reference
        int ref;
        for(int i = 0; i < 2 * n; ++i) {
            if(!used[i]) {
                ref = i;
                break;                
            }            
        }       
        used[ref] = 1;
        double res = 1e18;
        for(int i = ref + 1; i < 2 * n; ++i) {
            if(used[i])
                continue;
            used[i] = 1;
            res = min(res, generate(idx + 1, cur_dist + sqrt(sqr(a[ref].fi - a[i].fi) + sqr(a[ref].se - a[i].se))));
            used[i] = 0;
        }
        used[ref] = 0;         
        return res;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int tcnum = 1;
    while(true) {
        cin >> n;
        if(n == 0)
            return 0;
        cout << "Case " << tcnum++ << ": ";
        string buang;
        for(int i = 0; i < 2 * n; ++i)
            cin >> buang >> a[i].fi >> a[i].se;
        cout << fixed << setprecision(2) << generate(0, 0) << endl;   
    }
    return 0;
}