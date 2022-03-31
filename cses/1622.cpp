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
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    ll fact[s.size() + 1];
    fact[0] = 1;
    for(int i = 1; i <= s.size(); ++i)
        fact[i] = fact[i - 1] * i;
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for(auto i : s)
        ++cnt[i - 'a'];
    ll res = fact[s.size()];
    for(int i = 0; i < 26; ++i)
        res /= fact[cnt[i]];
    cout << res << endl;
    do {
        cout << s << endl;
    } while(next_permutation(s.begin(), s.end()));
    return 0;
}