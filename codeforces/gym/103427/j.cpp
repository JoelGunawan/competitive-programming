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
char prev(char a) {
    if(a == '0')
        return '9';
    else
        return --a;
}
char next(char a) {
    if(a == '9')
        return '0';
    else
        return ++a;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // shortest path from 0000 to all
    // shift queries to 0000 to something
    const int lim = 1e4 + 5;
    int dist[lim];
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> bfs;
    bfs.push(mp(0, 0));
    vector<int> edges[lim];
    for(int i = 0; i < 1e4; ++i) {
        // make edges
        // consider the string, and consider every possible l, r shift up and down
        string s = to_string(i);
        while(s.size() < 4)
            s = "0" + s;
        for(int j = 0; j < s.size(); ++j) {
            for(int k = j; k < s.size(); ++k) {
                // shift up or shift down
                for(int l = j; l <= k; ++l) {
                    s[l] = next(s[l]);
                }
                edges[i].pb(stoi(s));
                for(int l = j; l <= k; ++l) {
                    s[l] = prev(s[l]);
                    s[l] = prev(s[l]);
                }
                edges[i].pb(stoi(s));
                for(int l = j; l <= k; ++l) {
                    s[l] = next(s[l]);
                }
            }
        }
    }
    while(bfs.size()) {
        int d = bfs.front().fi, nd = bfs.front().se;
        bfs.pop();
        if(dist[nd] != -1)
            continue;
        dist[nd] = d;
        for(auto i : edges[nd]) {
            if(dist[i] == -1)
                bfs.push(mp(d + 1, i));
        }
    }
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        int num = 0;
        for(int i = 0; i < 4; ++i) {
            int cur = 0;
            while(a[i] != b[i]) {
                b[i] = prev(b[i]);
                ++cur;
            }
            num = num * 10 + cur;
        }
        cout << dist[num] << endl;
    }
    return 0;
}