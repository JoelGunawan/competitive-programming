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
bool edges[2005][2005];
vector<int> previous[3];
int n, m;
void brute_force(int idx, int c) {
    //cout << idx << " " << c << endl;
    if(idx == n + 1) {
        for(auto i : previous[0])
            cout << i << " ";
        cout << endl;
        for(auto i : previous[1])
            cout << i << " ";
        cout << endl;
        exit(0);
    }
    for(auto i : previous[c])
        if(!edges[idx][i])
            return;
    previous[c].pb(idx);
    for(int i = 0; i < 3; ++i)
        brute_force(idx + 1, i);
    previous[c].pop_back();
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u][v] = 1;
        edges[v][u] = 1;
    }
    previous[0].pb(1);
    previous[1].pb(2);
    brute_force(3, 0);
    brute_force(3, 1);
    brute_force(3, 2);
    cout << "impossible" << endl;
    return 0;
}