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
        int pref[n + 1];
        s = " " + s;
        pref[0] = 0;
        for(int i = 1; i <= n; ++i)
            pref[i] = pref[i - 1] + s[i] - '0';
        vector<int> num(n);
        for(int i = n; i >= 1; --i) {
            int pos = n - i;
            num[pos] = pref[i];
        }
        int idx = 0;
        while(idx < num.size()) {
            if(num[idx] >= 10) {
                if(idx == num.size() - 1)
                    num.pb(num[idx] / 10);
                else
                    num[idx + 1] += num[idx] / 10;
                num[idx] %= 10;
            }
            ++idx;
        }
        while(num.size() > 1 && num.back() == 0)
            num.pop_back();
        reverse(num.begin(), num.end());
        for(auto i : num)
            cout << i;
        cout << endl;
    }
    return 0;
}