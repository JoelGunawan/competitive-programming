// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
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
    int n, m, k;
    cin >> n >> m >> k;
    // set go brrrrrrrrr
    set<pair<int, int>> a;
    set<int> available;
    for(int i = 1; i <= n; ++i)
        a.ins(mp(0, i));
    int cil = n % m, floor = m - cil;
    for(int i = 0; i < k; ++i) {
        for(int j = 1; j <= n; ++j)
            available.insert(j);
        for(int line = 0; line < cil; ++line) {
            cout << n / m + 1 << " ";
            for(int j = 0; j < n / m + 1; ++j) {
                // take first from a
                cout << (*a.begin()).se << " ";
                pair<int, int> x = *a.begin();
                a.erase(a.begin());
                ++x.fi;
                a.ins(x);
                available.erase(available.find(x.se));
            }
            cout << endl;
        }
        for(int line = 0; line < floor; ++line) {
            cout << n / m << " ";
            for(int j = 0; j < n / m; ++j) {
                cout << *available.begin() << " ";
                available.erase(available.begin());
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}