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
    // divisible by 8 -> last three digits divisible by 8
    // coba cari semua 3 digit combination yang divisible by 8
    // cari dari belakang (as subsequence)
    // special case 000, 008, 080 (leading zero)
    string s;
    cin >> s;
    s = " " + s;
    int ans = 2e9;
    int n = s.size() - 1;
    for(int i = 0; i < 1000; i += 8) {
        // cari subsequence
        // buat jadi string
        string t = to_string(i);
        while(t.size() < 3) {
            int last_idx = -1, cur_idx = t.size() - 1;
            for(int j = n; j >= 1; --j) {
                if(t[cur_idx] == s[j])
                    --cur_idx;
                if(cur_idx == -1) {
                    last_idx = j;
                    cout << t << endl;
                    exit(0);
                    break;
                }
            }
            if(last_idx != -1)
                ans = min(ans, n - last_idx - (int)t.size() + 1);
            t = "0" + t;
        }
        // t.size() sudah == 3
        // cari subsequence ini
        int last_idx = -1, cur_idx = 2;
        for(int j = n; j >= 1; --j) {
            if(t[cur_idx] == s[j])
                --cur_idx;
            if(cur_idx == -1) {
                last_idx = j;
                cout << t << endl;
                exit(0);
                break;
            }
        }
        if(last_idx != -1)
            ans = min(ans, n - last_idx - 2);
    }
    cout << -1 << endl;
    return 0;
}