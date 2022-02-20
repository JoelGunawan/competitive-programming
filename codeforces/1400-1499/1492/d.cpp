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
void f() {
    cout << "No" << endl;
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, k;
    cin >> a >> b >> k;
    if(k == 0) {
        cout << "Yes" << endl;
        for(int i = 1; i <= b; ++i) {
            cout << '1';
        }
        for(int j = 1; j <= a; ++j)
            cout << '0';
        cout << endl;
        for(int i = 1; i <= b; ++i)
            cout << '1';
        for(int j = 1; j <= a; ++j)
            cout << '0';
        cout << endl;
    }
    else if(b == 1 && k)
        f();
    else if(a == 0 && k)
        f();
    else if(a + b - 2 < k)
        f();
    else {
        cout << "Yes" << endl;
        string x = "", y = "";
        x = '1', y = '1';
        --b;
        while(a + b - 1 > k && a > 1)
            --a, x += '0', y += '0';
        while(a + b - 1 > k && b > 1)
            --b, x += '1', y += '1';
        x += '1', y += '0';
        for(int i = 0; i < a - 1; ++i)
            x += '0', y += '0';
        for(int i = 0; i < b - 1; ++i)
            x += '1', y += '1';
        x += '0', y += '1';
        cout << x << endl << y << endl;
    }
    return 0;
}