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
    // maintain minimum color for each node when we color another node
    // make count of adjacent for each neighbour node that we visit
    // each color -> connected component
    // set 1 as root
    // from root -> go to 2 and 3
    // from 2 and 3, go to their min child
    // and go to their min child
    // ...
    // use euler tour
    // use range updates?
    return 0;
}