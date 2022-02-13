// header file
#include <bits/stdc++.h>
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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int p[n];
    for(int i = 0; i < n; ++i)
        cin >> p[i];
    int left_increasing[n], right_increasing[n];
    memset(left_increasing, 0, sizeof(left_increasing));
    memset(right_increasing, 0, sizeof(right_increasing));
    for(int i = 1; i < n; ++i) {
        if(p[i] > p[i - 1])
            left_increasing[i] = left_increasing[i - 1] + 1;
    }
    for(int i = n - 2; i >= 0; --i) {
        if(p[i] > p[i + 1])
            right_increasing[i] = right_increasing[i + 1] + 1;
    }
    // make a vector of longest increasing
    vector<pair<int, int>> longest_increasing;
    for(int i = 0; i < n; ++i) {
        if(i == 0 || right_increasing[i] != right_increasing[i - 1] - 1)
            longest_increasing.pb(mp(right_increasing[i], i));
    }
    for(int i = n - 1; i >= 0; --i) {
        if(i == n - 1 || left_increasing[i] != left_increasing[i + 1] - 1)
            longest_increasing.pb(mp(left_increasing[i], i));
    }
    longest_increasing.pb(mp(-1, -1));
    sort(longest_increasing.begin(), longest_increasing.end());
    reverse(longest_increasing.begin(), longest_increasing.end());
    int res = 0;
    for(int i = 1; i < n - 1; ++i) {
        // check if it is a hill
        if(p[i] > p[i - 1] && p[i] > p[i + 1]) {
            // check longest distance that is not in the current hill
            int idx = 0;
            while(longest_increasing[idx].se == i)
                ++idx;
            // daniel chooses other than from current hill
            if(longest_increasing[idx].fi >= max(left_increasing[i], right_increasing[i]))
                continue;
            int l = left_increasing[i], r = right_increasing[i];
            if((l & 1 && l >= r) || (l % 2 == 0 && l - 1 >= r))
                continue;
            if((r & 1 && r >= l) || (r % 2 == 0 && r - 1 >= l))
                continue;
            ++res;
        }
    }
    //for(auto i : longest_increasing)
    //    cout << i.fi << " " << i.se << endl;
    //for(int i = 0; i < n; ++i)
    //    cout << left_increasing[i] << " ";
    //cout << endl;
    //for(int i = 0; i < n; ++i)
    //    cout << right_increasing[i] << " ";
    //cout << endl;
    cout << res << endl;
    return 0;
}