#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ll long long
#define lll __int128
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
using namespace std;
void tc() {
    int b[7];
    for(int i = 0; i < 7; ++i)
        cin >> b[i];
    cout << b[0] << " " << b[1] << " " << b[6] - b[1] - b[0] << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();    
    return 0;
}