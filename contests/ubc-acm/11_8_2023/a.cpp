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
        int n;
        string s;
        cin >> n >> s;
        // try every value of x and y
        int a = 0, b = 0;
        // try x = i
        for(int i = 1; i <= n; ++i) {
            int x = i;
            for(int j = 1; j <= n; ++j) {
                int y = j;
                // for given x, y simulate
                int aset = 0, bset = 0;
                bool set_end = 0;
                int cura = 0, curb = 0;
                for(int k = 1; k <= n; ++k) {
                    set_end = 0;
                    if(s[k - 1] == 'A')
                        ++cura;
                    else
                        ++curb;

                    if(cura >= x) {
                        ++aset;
                        cura = 0, curb = 0;
                        if(aset > bset)
                            set_end = 1;
                    }
                    else if(curb >= x) {
                        ++bset;
                        cura = 0, curb = 0;
                        if(bset > aset)
                            set_end = 1;
                    }
                }
                if(aset != bset && set_end && max(aset, bset) == y) {
                    //cout << x << " " << y << endl;
                    if(aset > bset)
                        ++a;
                    else
                        ++b;
                }
            }
        }
        //cout << a << " " << b << endl;
        if((a && b) || (!a && !b)) {
            cout << "?" << endl;
        }
        else if(a) 
            cout << "A" << endl;
        else
            cout << "B" << endl;
    }
    return 0;
}