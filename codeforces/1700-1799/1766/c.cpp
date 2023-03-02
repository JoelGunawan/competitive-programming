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
void tc() {
    int m;
    cin >> m;
    string s[2];
    cin >> s[0] >> s[1];
    bool ans = 1;
    for(int i = 0; i < m - 1; ++i) {
        if((s[0][i] == 'W' && s[1][i + 1] == 'W') || (s[1][i] == 'W' && s[0][i + 1] == 'W')) {
            cout << "NO" << endl;
            return;
        }
    }
    int start = 0, end = m - 1;
    while(start < m && s[0][start] == s[1][start] && s[0][start] == 'B')
        ++start;
    while(end && s[0][end] == s[1][end] && s[0][end] == 'B')
        --end;
    if(start >= end) {
        cout << "YES" << endl;
        return;
    }
    bool spos = s[1][start] == 'B';
    for(int i = start; i <= end; ++i) {
        if(s[0][i] == s[1][i] && s[0][i] == 'B')
            spos = !spos;
        else if(s[0][i] == 'B') {
            if(spos) {
                cout << "NO" << endl;
                return;
            }
        }
        else {
            if(!spos) {
                cout << "NO" << endl;
                return;
            }
        }
    }
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