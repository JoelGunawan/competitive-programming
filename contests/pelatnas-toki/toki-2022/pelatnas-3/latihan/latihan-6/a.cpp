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
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    // either greedy L first or R first, choose minimum
    int l = 0, r = n - 1;
    vector<pair<int, int>> operations;
    while(a != b && l <= r) {
        if(a[l] == b[l]) {
            ++l;
            continue;
        }
        if(a[r] == b[r]) {
            --r;
            continue;
        }
        int idxl = -1, idxr = -1;
        for(int i = l; i <= r; ++i) {
            // find L
            // find R
            if(a[i] == b[l])
                idxl = i;
            if(a[i] == b[r])
                idxr = i;
        }
        // cari idxl ke kiri berapa
        vector<pair<int, int>> left, right;
        vector<int> leftres, rightres;
        bool minl = 0, minr = 0;
        for(int i = idxl - 1; i >= l; --i) {
            if(left.size() == 0) {
                if(a[i] < b[l])
                    minl = 0;
                else
                    minl = 1;
                left.push_back(mp(a[i], i));
            }
            else {
                if(minl) {
                    while(left.size() && a[i] > left.back().fi) {
                        left.pop_back();
                    }
                    if(a[i] < b[l]) {
                        // harus transisi ke minl
                        minl = !minl;
                        for(auto i : left)
                            leftres.pb(i.se);
                        left.clear();
                    }
                    left.pb(mp(a[i], i));
                }
                else {
                    while(left.size() && a[i] < left.back().fi)
                        left.pop_back();
                    if(a[i] > b[l]) {
                        minl = !minl;
                        for(auto i : left)
                            leftres.pb(i.se);
                        left.clear();
                    }
                    left.pb(mp(a[i], i));
                }
            }
        }
        for(auto i : left)
            leftres.pb(i.se);
        for(int i = idxr + 1; i <= r; ++i) {
            if(right.size() == 0) {
                if(a[i] < b[r])
                    minr = 0;
                else
                    minr = 1;
                right.push_back(mp(a[i], i));
            }
            else {
                if(minr) {
                    while(right.size() && a[i] > right.back().fi)
                        right.pop_back();
                    if(a[i] < b[r]) {
                        // harus transisi ke minl
                        minr = !minr;
                        for(auto i : right)
                            rightres.pb(i.se);
                        right.clear();
                    }
                    right.pb(mp(a[i], i));
                }
                else {
                    while(right.size() && a[i] < right.back().fi)
                        right.pop_back();
                    if(a[i] > b[r]) {
                        minr = !minr;
                        for(auto i : right)
                            rightres.pb(i.se);
                        right.clear();
                    }
                    right.pb(mp(a[i], i));
                }
            }
        }
        for(auto i : right)
            rightres.pb(i.se);
        if(true) {
            // go for leftres
            int pr = idxl;
            for(int i = leftres.size() - 1; i >= 0; --i)
                swap(a[leftres[i]], a[idxl]);
            for(int i = 0; i < leftres.size(); ++i) {
                operations.pb(mp(leftres[i], pr)), pr = leftres[i];
            }
            ++l;
        }
        else {
            // go for rightres
            int pr = idxr;
            //cout << "RIGHTRES " << endl;
            //for(auto i : rightres) {
            //    cout << i << " ";
            //}
            //cout << endl;
            for(int i = rightres.size() - 1; i >= 0; --i)
                swap(a[rightres[i]], a[idxr]);
            for(int i = 0; i < rightres.size(); ++i) {
                operations.pb(mp(pr, rightres[i])), pr = rightres[i];
            }
            --r;
        }
    }
    cout << operations.size() << endl;
    for(auto i : operations)
        cout << i.fi + 1 << " " << i.se + 1 << endl;
    
    return 0;
}