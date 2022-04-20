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
    vector<int> main_cnt(26, 0);
    vector<vector<int>> aux_cnt(n, vector<int>(26, 0));
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        main_cnt[s[0] - 'A']++;
        for(auto j : s)
            aux_cnt[i][j - 'A']++;
    }
    for(int i = 0; i < n; ++i) {
        bool ans = 1;
        for(int j = 0; j < 26; ++j) {
            if(!main_cnt[j] && aux_cnt[i][j])
                ans = 0;
        }
        if(ans)
            cout << "Y" << endl, exit(0);
    }
    cout << "N" << endl;
    return 0;
}