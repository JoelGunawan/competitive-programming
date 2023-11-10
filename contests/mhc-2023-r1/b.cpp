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
    int c = 0;
    while(t--) {
        ++c;
        int p;
        cin >> p;
        vector<int> v;
        for(int i = 2; i <= sqrt(p); ++i) {
            while(p % i == 0)
                v.pb(i), p /= i;
        }
        if(p > 1)
            v.pb(p);
        int sum = 0;
        for(auto i : v)
            sum += i;
        cout << "Case #" << c << ":";
        if(sum > 41) {
            cout << -1 << endl;
        }
        else {
            while(sum < 41)
                v.pb(1), ++sum;
            cout << " ";
            cout << v.size() << " ";
            for(auto i : v)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}