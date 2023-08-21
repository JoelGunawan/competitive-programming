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
    int n;
    cin >> n;
    int a[n + 1];
    bool used[n + 1];
    memset(used, 0, sizeof(used));
    map<int, int> valid_check;
    for(int i = 1; i <= n; ++i)
        cin >> a[i], valid_check[a[i]]++;    
    for(auto i : valid_check) {
        if(i.se & 1) {
            cout << -1 << endl;
            return;
        }
    }
    int pad = 0;
    vector<pair<int, int>> ops;
    vector<int> segment;
    for(int i = 1; i <= n; ++i) {
        if(!used[i]) {
            int pad2 = pad;
            int cur_seg = 0;
            for(int j = i + 1; j <= n; ++j) {
                if(used[j])
                    --pad2;
                if(a[i] == a[j] && !used[j]) {
                    used[i] = used[j] = 1;
                    // bxuat operasinya
                    int cur_idx = i;
                    for(int k = 0; k < cur_seg; ++k) {
                        while(used[cur_idx]) {
                            ++cur_idx;
                        }
                        // udah ga used, berarti nanti dimasukkin operasinya
                        ops.push_back(mp(j + pad2 + k, a[cur_idx]));
                        ++cur_idx;
                    }
                    segment.pb(2 * (cur_seg + 1));
                    pad += 2 * cur_seg + 1 ;
                    // swap posisi tiap elemen :D
                    int l = i + 1, r = j - 1;
                    for(int k = 0; k < cur_seg / 2; ++k) {
                        // swap kiri sama kanan
                        while(used[l])
                            ++l;
                        while(used[r])
                            --r;
                        swap(a[l], a[r]);
                        ++l, --r;
                    }
                    break;
                }
                if(!used[j])
                    ++cur_seg;
            }

        }
        else
            --pad;
    }
    cout << ops.size() << endl;
    for(auto i : ops)
        cout << i.fi << " " << i.se << endl;
    cout << segment.size() << endl;
    for(auto i : segment)
        cout << i << " ";
    cout << endl;
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