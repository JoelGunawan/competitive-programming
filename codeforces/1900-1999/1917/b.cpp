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
        string s;
        cin >> n >> s;
        s = " " + s;
        int exists[26];
        memset(exists, 0, sizeof(exists));
        int res = 0;
        exists[s[1] - 'a']++;
        for(int i = 2; i <= n; ++i) {
            // find count of exists that is not equal to previous
            ++res;
            for(int j = 0; j < 26; ++j) {
                if(j != s[i - 1] - 'a' && exists[j]) {
                    ++res;
                }
            }
            ++exists[s[i] - 'a'];
        }
        for(int i = 0; i < 26; ++i) {
            if(exists[i])
                ++res;
        }
        cout << res << endl;
    }
    return 0;
}