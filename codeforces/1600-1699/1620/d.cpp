// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
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
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    // optimal way -> take no more than 3/4 coins of value 2 ?
    // take no more than 1 coins of value 1
    int one = 0, two = 0;
    int maximum = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] % 3 == 1)
            one = 1;
        else if(a[i] % 3 == 2)
            two = 1;
        maximum = max(a[i], maximum);
    }
    sort(a, a + n);
    if(a[0] != 1 && one == 1 && two == 1)
        ++two, --one;
    
    if(maximum % 3 == 0 && (two == 2 || one && two)) {
        cout << maximum / 3 + 1 << endl;
    }
    else if(maximum % 3 == 1 && two == 2) {
        bool ans = 1;
        for(int i = n - 1; i >= 0; --i) 
            if(a[i] == maximum - 1)
                ans = 0;
        if(ans)
            cout << maximum / 3 + 1 << endl;
        else
            cout << maximum / 3 + two << endl;
    }
    else
        cout << maximum / 3 + one + two << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}