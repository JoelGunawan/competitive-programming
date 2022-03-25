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
vector<pair<int, int>> positive;
vector<pair<int, pair<int, int>>> negative;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, r;
    cin >> n >> r;
    // positive -> lowest required rating
    // negative -> choose highest required rating first
    // select projects below the highest required rating such that the decrease caused by that project would not cause
    // the current rating to be lower than the highest required rating
    // greedy on highest
    for(int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if(b >= 0) {
            positive.pb(mp(a, b));
        }
        else
            negative.pb(mp(max(a, -b) + b, mp(a, b)));
    }
    sort(positive.begin(), positive.end());
    sort(negative.begin(), negative.end());
    reverse(negative.begin(), negative.end());
    bool exists = 1;
    int res = n;
    for(auto i : positive) {
        if(i.fi > r)
            exists = 0;
        else
            r += i.se;
    }
    for(auto i : negative) {
        if(i.se.fi > r) 
            exists = 0;
        else
            r += i.se.se;
    }
    if(exists && r >= 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}