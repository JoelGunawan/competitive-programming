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
    int t;
    cin >> t;
    while(t--) {
        int p1, p2;
        double x1, x2;
        cin >> x1 >> p1 >> x2 >> p2;
        while(x1 >= 10)
            x1 /= 10, ++p1;
        while(x2 >= 10)
            x2 /= 10, ++p2;
        if(x1 == x2 && p1 == p2)
            cout << "=" << endl;
        else if(p1 > p2 || (p1 == p2 && x1 > x2))
            cout << ">" << endl;
        else
            cout << "<" << endl;
    }
    return 0;
}