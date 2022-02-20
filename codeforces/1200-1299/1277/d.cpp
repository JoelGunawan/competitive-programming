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
    int n;
    cin >> n;
    pair<string, int> a[n];
    string b[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].fi, a[i].se = i, b[i] = a[i].fi;
    sort(b, b + n);
    int pure[2];
    memset(pure, 0, sizeof(pure));
    int fixed = 0;
    vector<int> onestart, oneend;
    for(int i = 0; i < n; ++i) {
        string t;
        t = a[i].fi;
        reverse(t.begin(), t.end());
        if(a[i].fi[0] == a[i].fi[a[i].fi.size() - 1])
            ++pure[a[i].fi[0] - '0'];
        else if(binary_search(b, b + n, t)) {
            ++fixed;
        }
        else {
            // which means we can reverse this
            if(a[i].fi[0] == '0')
                onestart.pb(a[i].se);
            else
                oneend.pb(a[i].se);
        }
    }
    if(pure[0] && pure[1] && !onestart.size() && !oneend.size() && !fixed) {
        cout << -1 << endl;
    }
    else {
        vector<int> operations;
        while(onestart.size() > oneend.size() + 1) {
            oneend.pb(onestart.back());
            onestart.pop_back();
            operations.pb(oneend.back());
        }
        while(oneend.size() > onestart.size() + 1) {
            onestart.pb(oneend.back());
            oneend.pop_back();
            operations.pb(onestart.back());
        }
        cout << operations.size() << endl;
        for(auto i : operations)
            cout << i + 1 << " ";
        cout << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}