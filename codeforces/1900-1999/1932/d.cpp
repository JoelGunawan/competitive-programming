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
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        char c;
        cin >> n >> c;
        int trumpidx;
        int cnt[4];
        char a[] = {'C', 'D', 'H', 'S'};
        for(int i = 0; i < 4; ++i)
            if(a[i] == c)
                trumpidx = i;
        memset(cnt, 0, sizeof(cnt));
        vector<string> cards[4];
        for(int i = 1; i <= 2 * n; ++i) {
            string s;
            cin >> s;
            for(int j = 0; j < 4; ++j) {
                if(s[1] == a[j]) {
                    ++cnt[j];
                    cards[j].pb(s);
                }
            }
        }

        for(int i = 0; i < 4; ++i) {
            sort(cards[i].begin(), cards[i].end());
        }
        vector<pair<string, string>> v;
        vector<string> need;
        for(int i = 0; i < 4; ++i) {
            if(i == trumpidx)
                continue;
            while(cards[i].size() >= 2) {
                v.pb(mp(cards[i].back(), cards[i][cards[i].size() - 2]));
                cards[i].pop_back();
                cards[i].pop_back();
            }
            if(cards[i].size())
                need.pb(cards[i].back());
        }
        if(need.size() > cards[trumpidx].size()) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        while(need.size()) {
            v.pb(mp(cards[trumpidx].back(), need.back()));
            need.pop_back();
            cards[trumpidx].pop_back();
        }
        while(cards[trumpidx].size()) {
            v.pb(mp(cards[trumpidx].back(), cards[trumpidx][cards[trumpidx].size() - 2]));
            cards[trumpidx].pop_back();
            cards[trumpidx].pop_back();
        }
        for(auto i : v) {
            cout << i.se << " " << i.fi << endl;
        }
    }
    return 0;
}