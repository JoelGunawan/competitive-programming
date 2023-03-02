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
    string s;
    cin >> s;
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < s.size(); ++i) {
        cnt[s[i] - 'a']++;
    }
    vector<int> a;
    for(int i = 0; i < 26; ++i) {
        if(cnt[i])
            a.pb(cnt[i]);
    }
    for(int i = 1; i < a.size(); ++i) {
        if(a[i] >= a[i - 1]) {
            cout << "false" << endl;
            return 0;
        }
    }
    cout << "true" << endl;
    return 0;
}