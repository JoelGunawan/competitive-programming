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
    string s, t;
    cin >> s >> t;
    bool pairs[18][18];
    memset(pairs, 0, sizeof(pairs));
    // precomp each pair
    for(int i = 0; i < 18; ++i) {
        for(int j = i; j < 18; ++j) {
            string x = "", y = "";
            for(char a : s) {
                if(a == 'a' + i || a == 'a' + j)
                    x += a;
            }
            for(char a : t) {
                if(a == 'a' + i || a == 'a' + j)
                    y += a;
            }
            if(x == y)
                pairs[i][j] = 1, pairs[j][i] = 1;
        }
    }
    int q;
    cin >> q;
    while(q--) {
        string query;
        cin >> query;
        bool ans = 1;
        for(int i = 0; i < query.size(); ++i) {
            for(int j = i; j < query.size(); ++j) {
                ans &= pairs[query[i] - 'a'][query[j] - 'a'];
            }
        }
        if(ans)
            cout << "Y";
        else
            cout << "N";
    }
    cout << endl;
    return 0;
}