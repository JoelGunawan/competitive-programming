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
    int a[6];
    for(int i = 0; i < 6; ++i)
        cin >> a[i];
    sort(a, a + 6, greater<int>());
    int n;
    cin >> n;
    // each note, 6 options
    // we can sort the options from highest to lowest
    // if we have a certain lower bound for the smallest minimum, we can find the maximum
    // binary search on b
    int b[n];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    // select one of the b's as minimum
    // use 2 pointers + sweep line approach
    // slowly increase the minimum and get the maximum
    // until we can't do no more
    // fi is fret number, se is idx
    set<pair<int, int>> s;
    for(int i = 0; i < n; ++i)
        s.ins(mp(b[i] - a[0], i));
    int res = (*--s.end()).fi - (*s.begin()).fi;
    while(true) {
        int prev = (*s.begin()).fi;
        bool esc = 0;
        //cout << prev << endl;
        while((*s.begin()).fi <= prev) {
            int idx = (*s.begin()).se;
            s.erase(s.begin());
            int x = -1;
            for(int i = 0; i < 6; ++i) {
                if(b[idx] - a[i] > prev) {
                    x = b[idx] - a[i];
                    break;
                }
            }
            if(x == -1) {
                esc = 1;
                break;
            }
            else {
                s.ins(mp(x, idx));
            }
        }
        if(esc)
            break;
        else
            res = min(res, (*--s.end()).fi - (*s.begin()).fi);
    }
    cout << res << endl;
    return 0;
}