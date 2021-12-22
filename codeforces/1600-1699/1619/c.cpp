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
        string a, s;
        cin >> a >> s;
        int a_idx = a.size() - 1;
        int s_idx = s.size() - 1;
        string res = "";
        bool ans = 1;
        while(a_idx >= 0 && s_idx >= 0) {
            if(s[s_idx] >= a[a_idx])
                res += '0' + s[s_idx] - a[a_idx], --s_idx, --a_idx;
            else {
                if(s_idx == 0 || s[s_idx - 1] != '1')
                    ans = 0;
                res += '0' + 10 + s[s_idx] - a[a_idx], --a_idx, s_idx -= 2;
            }
        }
        while(s_idx >= 0)
            res += s[s_idx--];
        reverse(res.begin(), res.end());
        while(res.size() > 0 && res[0] == '0')
            res.erase(0, 1);
        if(a_idx >= 0 || !ans)
            cout << -1 << endl;
        else
            cout << res << endl;
    }
    return 0;
}