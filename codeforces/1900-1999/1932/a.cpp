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
        cin >> n;
        string s;
        cin >> s;
        int idx = 0;
        int res = 0;
        while(idx + 1 < n) {
            if(s[idx + 1] == '*') {
                if(idx + 2 >= n)
                    break;
                else if(s[idx + 2] == '*')
                    break;
                else {
                    if(s[idx + 2] == '.')
                        idx += 2;
                    else
                        idx += 2, ++res;
                }
            }
            else {
                if(s[idx + 1] == '@')
                    ++res;
                ++idx;
            }
        }
        cout << res << endl;
    }
    return 0;
}