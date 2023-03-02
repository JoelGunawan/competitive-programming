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
    string s;
    cin >> s;
    int cnt = 0, idx;
    for(int i = 0; i < n; ++i) {
        if(s[i] != 'm' && s[i] != 'M') {
            idx = i;
            if(cnt == 0) {
                cout << "NO" << endl;
                return;
            }
            break;
        }
        ++cnt;
    }
    cnt = 0;
    for(int i = idx; i < n; ++i) {
        if(s[i] != 'e' && s[i] != 'E') {
            idx = i;
            if(cnt == 0) {
                cout << "NO" << endl;
                return;
            }
            break;
        }
        ++cnt;
    }
    cnt = 0;
    for(int i = idx; i < n; ++i) {
        if(s[i] != 'o' && s[i] != 'O') {
            idx = i;
            if(cnt == 0) {
                cout << "NO" << endl;
                return;
            }
            break;
        }
        ++cnt;
    }
    cnt = 0;
    for(int i = idx; i < n; ++i) {
        if(s[i] != 'w' && s[i] != 'W') {
            if(cnt == 0) {
                cout << "NO" << endl;
                return;
            }
            break;
        }
        idx = i;
        ++cnt;
    }
    //cout << "TEST" << " " << idx << endl;
    if(idx != n - 1)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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