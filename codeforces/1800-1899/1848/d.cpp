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
int a[] = {2, 4, 8, 6};
ll eval(int a, int start) {

}
void tc() {
    int s, k;
    cin >> s >> k;
    if(s % 10 == 0) {
        cout << 1ll * s * k << endl;
    }
    else if(s % 5 == 0) {
        // bisa tambah sekali atau ga ditambah sama sekali
        cout << max(1ll * s * k, 1ll * (s + 5) * (k - 1)) << endl;
    }
    else if(s & 1) {
        // ada 1 elem tambahan, terus ikut cycle 2, 4, 6, 8
        // di ternary search optimalnya dmn
        int a[] = {2, 4, 8, 6};
        int tot = 0;
        int start_idx;
        for(int i = 0; i < 4; ++i) {
            if(a[i] == ((2 * s) % 10))
                start_idx = i;
            tot += a[i];
        }
        int l = 0, r = k - 1;
        while(r - l > 20) {
            int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
            // calculate bonus klo mid1 dan mid2
            // bisa ada variance di antara range (hampir monotonic tapi ga sepenuhnya monotonic)
            assert(m1 < m2 && m1 != 0);
            unsigned ll bonus1 = 0;
            for(int j = m1; j < m1 + 4; ++j) {
                int sisa1 = k - j - 1;
                int full1 = (j - 1) / 4, ex = (j - 1) % 4, tmp1 = 0;
                for(int i = 0, idx = start_idx; i < ex; ++i, idx = (idx + 1) % 4) {
                    tmp1 += a[idx];
                }
                tmp1 += s % 10;
                bonus1 = max(bonus1, (1ull * full1 * tot + tmp1 + s) * sisa1);
            }
            unsigned ll bonus2 = 0;
            for(int j = m2 - 3; j <= m2; ++j) {
                int sisa2 = k - j - 1;
                int full2 = (j - 1) / 4, tmp2 = 0, ex = (j - 1) % 4;
                for(int i = 0, idx = start_idx; i < ex; ++i, idx = (idx + 1) % 4) {
                    tmp2 += a[idx];
                }
                tmp2 += s % 10;
                bonus2 = max(bonus2, (1ull * full2 * tot + tmp2 + s) * sisa2);
            }
            if(bonus1 < bonus2) 
                l = m1;
            else
                r = m2;
        }
        // assume i = 0 (gada transformation)
        unsigned ll res = 1ll * s * k;
        for(int i = l; i <= r; ++i) {
            if(i > 0) {
                int m1 = i - 1;
                int sisa1 = k - m1 - 1;
                int full1 = m1 / 4, ex = m1 % 4, tmp1 = 0;
                for(int i = 0, idx = start_idx; i < ex; ++i, idx = (idx + 1) % 4) {
                    tmp1 += a[idx];
                }
                tmp1 += s % 10;
                //cout << full1 << " " << tot << " " << tmp1 << " " << s << " " << sisa1 << endl;
                res = max(res, (1ull * full1 * tot + tmp1 + s) * sisa1);
            }
        }
        //cout << sisa1 << " " << full1 << " " << tmp1 << endl;
        //cout << l << " " << 1ull * full1 * tot << " " << tmp1 << " " << s << " " << sisa1 << endl;
        cout << res << endl;
    }
    else {
        // pasti ikut cycle 2, 4, 8, 6
        // di ternary search optimalnya dmn
        // sum each -> 
        int a[] = {2, 4, 8, 6};
        int tot = 0;
        int start_idx;
        for(int i = 0; i < 4; ++i) {
            if(a[i] == s % 10)
                start_idx = i;
            tot += a[i];
        }
        int l = 0, r = k - 1;
        while(r - l > 20) {
            int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
            // calculate bonus klo mid1 dan mid2
            // bisa ada variance di antara range (hampir monotonic tapi ga sepenuhnya monotonic)
            unsigned ll bonus1 = 0;
            
            for(int j = m1; j < m1 + 4; ++j) {
                int sisa1 = k - j;
                int full1 = j / 4, ex = j % 4, tmp1 = 0;
                for(int i = 0, idx = start_idx; i < ex; ++i, idx = (idx + 1) % 4) {
                    tmp1 += a[idx];
                }
                bonus1 = max(bonus1, (1ull * full1 * tot + tmp1 + s) * sisa1);
            }
            unsigned ll bonus2 = 0;
            for(int j = m2 - 3; j <= m2; ++j) {
                int sisa2 = k - j;
                int full2 = j / 4, tmp2 = 0, ex = j % 4;
                for(int i = 0, idx = start_idx; i < ex; ++i, idx = (idx + 1) % 4) {
                    tmp2 += a[idx];
                }
                bonus2 = max(bonus2, (1ull * full2 * tot + tmp2 + s) * sisa2);
            }
            if(bonus1 < bonus2) 
                l = m1;
            else
                r = m2 - 1;
        }
        unsigned ll res = 0;
        for(int i = l; i <= r; ++i) {
            int m1 = i;
            int sisa1 = k - m1;
            int full1 = m1 / 4, ex = m1 % 4, tmp1 = 0;
            for(int i = 0, idx = start_idx; i < ex; ++i, idx = (idx + 1) % 4) {
                tmp1 += a[idx];
            }
            res = max(res, (1ull * full1 * tot + tmp1 + s) * sisa1);

        }
        //cout << sisa1 << " " << full1 << " " << tmp1 << endl;
        //cout << l << " " << 1ull * full1 * tot << " " << tmp1 << " " << s << " " << sisa1 << endl;
        cout << res << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
    return 0;
}