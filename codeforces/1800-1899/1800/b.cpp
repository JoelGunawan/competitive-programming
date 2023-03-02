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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt[26][2];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; ++i) {
        if(s[i] >= 'a')
            ++cnt[s[i] - 'a'][0];
        else
            ++cnt[s[i] - 'A'][1];
    }
    for(int i = 0; i < k; ++i) {
        bool change = 0;
        for(int j = 0; j < 26; ++j) {
            int low = cnt[j][0], high = cnt[j][1];
            if(abs(low - high) <= 1)
                continue;
            else {
                change = 1;
                if(low < high)
                    ++cnt[j][0], --cnt[j][1];
                else
                    ++cnt[j][1], --cnt[j][0];
                break;
            }
        }
    }
    int res = 0;
    for(int i = 0; i < 26; ++i)
        res += min(cnt[i][0], cnt[i][1]);
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}