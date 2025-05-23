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
    int a[n], b[n];
    set<int> s;
    for(int i = 0; i < n; ++i)
        cin >> a[i], b[i] = a[i];
    sort(b, b + n);
    bool ans = 0;
    for(int i = 0; i < n; ++i)
        if(a[i] != b[i])
            ans = 1;
    if(ans)
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