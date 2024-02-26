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
void tc() {
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    vector<int> loc[26];
    for(int i = n - 1; i >= 0; --i) {
        loc[s[i] - 'a'].pb(i);
    }
    bool ans = 1;
    for(auto c : t) {
        int idx = c - 'a';
        if(loc[idx].empty()) {
            ans = false;
            break;
        }
        for(int i = 0; i < idx; ++i) {
            while(loc[i].size() && loc[i].back() < loc[idx].back())
                loc[i].pop_back();
        }
        loc[idx].pop_back();
    }
    cout << (ans ? "YES" : "NO") << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}