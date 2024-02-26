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
    string s;
    cin >> s;
    int res = 0;
    for(int i = 0; i <= (int)s.size() - 5; ++i) {
        if(s.substr(i, 5) == "edgnb") {
            ++res;
        }
    }
    cout << res << endl;
    return 0;
}