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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    // get cnt array
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < s.size(); ++i)
        ++cnt[s[i] - 'a'];
    // minimize max
    // the remaining, choose minimum use greedy
    // init -> find max, then choose from max to min
    // after -> from remaining, if there are any other "throwaways" we can just dump there
    // else -> must append, if there is more than one type, just dump everything into one long word
    // else -> distribute evenly
    int u = 0, tmp = k; char m = 2;
    for(int i = 0; i < 26; ++i) {
        while(cnt[i] && tmp) {
            --cnt[i], --tmp;
            if(m != i + 'a')
                ++u, m = i + 'a';
        }
    }
    if(u > 1) {
        cout << m << endl;
        return;
    }
    memset(cnt, 0, sizeof(cnt));
    tmp = k;
    for(int i = 0; i < s.size(); ++i)
        ++cnt[s[i] - 'a'];
    for(int i = m - 'a'; i >= 0; --i) {
        while(cnt[i] && tmp) {
            --cnt[i], --tmp;
        }
    }
    // from remaining cnt, find u
    u = 0;
    for(int i = 0; i < 26; ++i) {
        if(cnt[i] > 0)
            ++u;
    }
    cout << m;
    if(u == 1) {
        int idx = 0;
        for(int i = 0; i < 26; ++i) {
            if(cnt[i] > 0)
                idx = i;
        }
        for(int i = 0; i < ceil(cnt[idx] / (double)k); ++i) {
            cout << (char)(idx + 'a');
        }
    }
    else {
        for(int i = 0; i < 26; ++i) {
            while(cnt[i])
                cout << (char)(i + 'a'), --cnt[i];
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}