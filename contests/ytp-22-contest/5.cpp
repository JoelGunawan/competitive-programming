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
    int cnt[101];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }
    for(int i = 1; i <= 100; ++i)
        cnt[i] >>= 1;
    vector<int> cur;
    cur.push_back(0);
    for(int i = 1; i <= 100; ++i) {
        vector<int> tmp;
        int last[i + 1];
        memset(last, -1, sizeof(last));
        for(auto j : cur) {
            int tmp2 = j % i, start = j / i, tmp3 = max(last[tmp2], start);
            for(int k = tmp3; k <= start + cnt[i]; ++k) {
                tmp.pb(k * i + tmp2);    
            }
            last[tmp2] = (start + cnt[i]) + 1;
        }
        cur = tmp;
        sort(cur.begin(), cur.end());
    }
    cout << cur.size() << endl;
    return 0;
}