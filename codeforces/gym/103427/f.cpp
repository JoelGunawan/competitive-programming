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
string encode(string s) {
    int cur = 0;
    bool vis[20];
    memset(vis, 0, sizeof(vis));
    char map[20];
    for(int i = s.size() - 1; i >= 0; --i) {
        if(!vis[s[i] - 'a']) {
            vis[s[i] - 'a'] = 1;
            map[s[i] - 'a'] = 'a' + cur;
            ++cur;
        }
    }
    for(int i = 0; i < s.size(); ++i)
        s[i] = map[s[i] - 'a'];
    return s;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    vector<string> v;
    for(int i = 1; i <= n; ++i) {
        v.pb(encode(s.substr(1, i)));
    }
    sort(v.begin(), v.end());
    cout << v.back() << endl;
    return 0;
}