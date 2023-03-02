
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int a, d;
    cin >> a >> d;
    pair<int, int> ascend[a], descend[d];
    for(int i = 0; i < a; ++i)
        cin >> ascend[i].fi >> ascend[i].se;    
    for(int i = 0; i < d; ++i)
        cin >> descend[i].fi >> descend[i].se;
    int ascenttime = 0, descendtime = 0, totaldist = 0;
    for(int i = 0; i < a; ++i) 
        ascenttime += ascend[i].se, totaldist += ascend[i].fi;
    for(int i = 0; i < d; ++i)
        descendtime += descend[i].se;
    double l = 0, r = min(ascenttime, descendtime);
    while(r - l > 1e-9) {
        double mid = (l + r) / 2;        
        double ascend_dist = 0, descend_dist = 0;
        int tmp = 0;
        for(int i = 0; i < a; ++i) {
            //cout << ascend_dist << endl;
            if(ascend[i].se + tmp < mid)
                tmp += ascend[i].se, ascend_dist += ascend[i].fi;
            else {
                ascend_dist += (mid - tmp) * ascend[i].fi / ascend[i].se;                
                //cout << ascend_dist << endl;
                break;
            }
        }            
        tmp = 0;
        for(int i = 0; i < d; ++i) {
            //cout << descend_dist << endl;
            if(descend[i].se + tmp < mid)
                tmp += descend[i].se, descend_dist += descend[i].fi;
            else {
                //cout << mid - tmp << " " << descend[i].fi << " " << descend[i].se << endl;
                descend_dist += (mid - tmp) * descend[i].fi / descend[i].se;                
                //cout << descend_dist << endl;
                break;
            }
        } 
        //cout << l << " " << r << " " << mid << " " << descend_dist << " " << ascend_dist << endl;
        if(descend_dist + ascend_dist >= totaldist)
            r = mid;
        else
            l = mid;
    }    
    cout << fixed << setprecision(6) << l << endl;
    return 0;
}