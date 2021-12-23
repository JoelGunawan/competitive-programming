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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if(n < 3) {
        cout << "No" << endl;
        return 0;
    }
    // 4 -> 10 -> 8, 2
    // 5 -> 15 -> 12, 3
    vector<int> a, b;
    int sum = 1ll * n * (n + 1) / 2;
    for(int i = 2; i <= sqrt(sum); ++i)
        if(sum % i == 0) {
            a.pb(i);
            break;
        }
    for(int i = 1; i <= n; ++i)
        if(a[0] != i)
            b.pb(i);
    cout << "Yes" << endl;
    cout << 1 << " " << a[0] << endl;
    cout << b.size() << " ";
    for(int i = 0; i < b.size(); ++i)
        cout << b[i] << " ";
    cout << endl;
    return 0;
}