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
    int n, x;
    cin >> n >> x;
    set<int> cur = {0};
    for(int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        set<int> nxt;
        for(auto i : cur) {
            if(i + a <= x)
                nxt.ins(i + a);
            if(i + b <= x)
                nxt.ins(i + b);
        }
        cur = nxt;
    }
    if(cur.find(x) != cur.end())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}