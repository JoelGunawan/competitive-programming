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
    int prefix[s.size()], suffix[s.size()];
    memset(prefix, 0, sizeof(prefix));
    int cur = 0;
    int res = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(cur == t.size())
            prefix[i] = prefix[i - 1];
        else {
            if(i == 0)
                prefix[i] = 0;
            else 
                prefix[i] = prefix[i - 1];
            if(s[i] == t[cur])
                ++prefix[i], ++cur;
            if(cur == t.size()) {
                res = max(res, (int)s.size() - i - 1);
            }
        }
    }
    memset(suffix, 0, sizeof(suffix));
    cur = t.size() - 1;
    for(int i = s.size() - 1; i >= 0; --i) {
        if(cur == -1) {
            suffix[i] = suffix[i + 1];
        }
        else {
            if(i == s.size() - 1)
                suffix[i] = 0;
            else
                suffix[i] = suffix[i + 1];
            if(s[i] == t[cur])
                ++suffix[i], --cur;
            if(cur == t.size()) {
                res = max(res, i);
            }
        }
    }
    for(int i = 0; i < s.size(); ++i) {
        if(i == 0) {
            int inverse = t.size(), l = i, r = s.size() - 1, y = 0;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(suffix[mid] >= inverse) {
                    l = mid + 1, y = mid;
                }
                else {
                    r = mid - 1;
                }
            }
            res = max(res, y - i);
        }
        else {
            // get minimum index
            int idx = i - 1, inverse = t.size() - prefix[i - 1], l = i, r = s.size() - 1, y = 0;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(suffix[mid] >= inverse) {
                    l = mid + 1, y = mid;
                }
                else {
                    r = mid - 1;
                }
            }
            res = max(res, y - i);
        }
    }
    cout << res << endl;
    return 0;
}