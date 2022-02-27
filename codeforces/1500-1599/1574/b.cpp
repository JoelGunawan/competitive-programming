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
void tc() {
    int m;
    vector<int> a;
    for(int i = 0; i < 3; ++i) {
        int x;
        cin >> x;
        a.pb(x);
    }
    cin >> m;
    sort(a.begin(), a.end(), greater<int>());
    int mini, maxi = 0;
    mini = max(0, a[0] - a[1] - a[2] - 1);
    for(auto i : a) {
        if(i > 0)
            maxi += i - 1;
    }
    if(m >= mini && m <= maxi)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}