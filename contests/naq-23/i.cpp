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
    string s;
    cin >> s;
    vector<int> ans;
    for(int i = 1; i <= 5; ++i) {
        if(s.size() >= i) {
            int cur = stoi(s.substr(0, i));
            if(s[0] == '0')
                continue;
            if(cur < 1 || cur > 99999)
                continue;
            int init = cur;
            if(s.size() == i) {
                if(cur != 1)
                    ans.pb(cur - 1);
                if(cur != 99999)
                    ans.pb(cur + 1);
                continue;
            }
            int idx = i;
            bool hm = 0, valid = 1;
            int pos = -1;
            while(idx < s.size()) {
                int nxsz = to_string(cur + 1).size();
                //cout << idx << " " << cur << endl;
                if(s.size() - idx < nxsz) {
                    valid = 0;
                    break;
                }
                if(s.substr(idx, nxsz) != to_string(cur + 1)) {
                    if(hm) {
                        valid = 0;
                        break;
                    }
                    else {
                        hm = 1;
                        pos = cur + 1;
                    }
                }
                else {
                    idx += nxsz;
                }
                ++cur;
            }
            if(valid) {
                if(hm)
                    ans.pb(pos);
                else {
                    if(init != 1)
                        ans.pb(init - 1);
                    if(cur != 99999)
                        ans.pb(cur + 1);
                }
            }
            //cout << hm << " " << valid << endl;
        }
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans.size() << endl;
    for(auto i : ans)
        cout << i << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // assume string length 1 2 3 4 5
    // coba cek klo misal di angka itu, skip berapa angka
    // klo misal di string length itu, berapa yg ke skip
    // panjang string harus kelipatan jumlah digit? 
    // tdk harus
    // klo misal panjang string = 1, 2, 3, 4, 5 berarti bs kurang ato tambah
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
    return 0;
}