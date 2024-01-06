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
        string s;
        cin >> s;
        int a[2];
        a[0] = a[1] = 0;
        for(auto i : s) {
            ++a[i - '0'];
        }
        int cnt = 0;
        for(auto i : s) {
            --a[!(i - '0')];
            if(a[!(i - '0')] < 0)
                break;
            ++cnt;
        }
        cout << s.size() - cnt << endl;
    }
    return 0;
}