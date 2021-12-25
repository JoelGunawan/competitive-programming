// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int res = INT_MAX;
        for(int i = 0; i < s.size(); ++i) {
            for(int j = i + 1; j < s.size(); ++j) {
                if(((s[i] - '0') * 10 + s[j] - '0') % 25 == 0)
                    res = min(res, (int)s.size() - i - 2);
            }
        }
        cout << res << endl;
    }
    return 0;
}