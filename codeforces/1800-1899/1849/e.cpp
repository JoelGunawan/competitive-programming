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
    // numbers of subarrays such that maxpos > minpos
    // loc of max bigger than loc of min
    // find left bigger element, right bigger element, left smaller element, right smaller element
    // positions where x is maximum and maxpos > minpos terjadi saat
    // l, r is within right larger/left larger element
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> mn, mx;
    int isi = 0;
    ll res = 0;
    for(int i = 1; i <= n; ++i) {
        while(mn.size() && a[mn.back()] > a[i]) {
            if(mn.size() == 1) {
                isi = 0;
            }
            else {
                int prmn = mn[mn.size() - 2], prmx = -1;
                if(ub(mx.begin(), mx.end(), mn.back()) != mx.begin()) {
                    prmx = *--ub(mx.begin(), mx.end(), mn.back());
                }
                //cout << "MN " << mn.back() << " " << max(prmn, prmx) << endl;
                isi -= mn.back() - max(prmn, prmx);
            }
            mn.pop_back();
        }
        //cout << "CHECK " << isi << endl;
        while(mx.size() && a[mx.back()] < a[i]) {
            if(mx.size() == 1) {
                // jadi empty, isi jadi i - 1
                //cout << "RESET" << endl;
                isi = i - 1;
            }
            else {
                // add to closest previous, antara mx atau mn
                int prmn = -1, prmx = mx[mx.size() - 2];
                if(lb(mn.begin(), mn.end(), mx.back()) != mn.begin())
                    prmn = *--lb(mn.begin(), mn.end(), mx.back());
                //cout << "MX " << mx.back() << " " << max(prmn, prmx) << " " << isi << " " << mx.back() - max(prmn, prmx) << endl;
                isi += mx.back() - max(prmn, prmx);
            }
            mx.pop_back();
        }
        //cout << isi << endl;
        res += isi;
        mx.pb(i);
        mn.pb(i);
        // mn -> simpan ke belakang new mn terjadi kapan aja
        // mx -> simpan ke belakang new mx terjadi kapan aja
        //cout << "MN " << i << endl;
        //for(auto i : mn)
        //    cout << a[i] << " ";
        //cout << endl;
        //cout << "MX " << i << endl;
        //for(auto i : mx)
        //    cout << a[i] << " ";
        //cout << endl;
    }
    cout << res << endl;
    return 0;
}