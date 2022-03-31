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
    int cur = 0; char prev = '0';
    int res = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] != prev) {
            res = max(res, cur);
            cur = 0;
            prev = s[i];
        }
        ++cur;
    }
    res = max(res, cur);
    cout << res << endl;
    return 0;
}