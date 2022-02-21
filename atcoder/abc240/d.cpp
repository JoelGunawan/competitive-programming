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
    int a[n];
    for(int i = 0; i < n; ++i) 
        cin >> a[i];
    // fi number, se count
    vector<pair<int, int>> segments = {{a[0], 1}};
    int idx = 1, cnt = 1;
    cout << 1 << endl;
    while(idx < n) {
        if(segments.back().fi == a[idx]) {
            ++segments.back().se;
            ++cnt;
            if(segments.back().fi == segments.back().se)
                cnt -= segments.back().fi, segments.pop_back();
        }
        else
            segments.pb(mp(a[idx], 1)), ++cnt;
        cout << cnt << endl;
        ++idx;
    }
    return 0;
}