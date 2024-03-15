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
void tc() {
    int n, k;
    cin >> n >> k;
    // cari kiri sama kanan, yang lebih bisa dihapus yg mana
    int curl = k, curr = k;
    ll a[n + 2];
    a[0] = 1e18, a[n + 1] = 1e18;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    // find first non negative value on the left and find the min value is how much
    ll init = a[k];
    ll l_neg = 0, new_l, r_neg = 0, new_r, cur = 0;
    for(int i = k - 1; i >= 0; --i) {
        cur += a[i];
        l_neg = min(l_neg, cur);
        if(cur > 0) {
            new_l = i;
            break;
        }
    }
    cur = 0;
    for(int i = k + 1; i <= n + 1; ++i) {
        cur += a[i];
        r_neg = min(r_neg, cur);
        if(cur > 0) {
            new_r = i;
            break;
        }
    }
    while(curl > 0 && curr < n + 1) {
        //cout << init << " " << l_neg << " " << r_neg << " " << curl << " " << curr << " " << new_l << " " << new_r << endl;
        if(init + l_neg >= 0) {
            for(int i = curl - 1; i >= new_l; --i)
                init += a[i];
            curl = new_l;
            l_neg = 0, cur = 0;
            for(int i = curl - 1; i >= 0; --i) {
                cur += a[i];
                l_neg = min(l_neg, cur);
                if(cur > 0) {
                    new_l = i;
                    break;
                }
            }
        }
        else if(init + r_neg >= 0) {
            for(int i = curr + 1; i <= new_r; ++i)
                init += a[i];
            curr = new_r;
            r_neg = 0, cur = 0;
            for(int i = curr + 1; i <= n + 1; ++i) {
                cur += a[i];
                r_neg = min(r_neg, cur);
                if(cur > 0) {
                    new_r = i;
                    break;
                }
            }
        }
        else
            break;
    }
    if(curl > 0 && curr < n + 1)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}