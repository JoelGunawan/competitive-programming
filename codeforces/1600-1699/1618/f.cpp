// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
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
bool solve(string a, string b) {
    // b is 111a111
    // basically that?
    //cout << a << " " << b << endl;
    for(int i = 0; i <= (int)b.size() - (int)a.size(); ++i) {
        //cout << i << endl;
        if(b.substr(i, a.size()) == a) {
            bool ans = 1;
            for(int j = 0; j < i; ++j) {
                if(b[j] == '0')
                    ans = 0;
            }
            for(int j = i + a.size(); j < b.size(); ++j) {
                if(b[j] == '0')
                    ans = 0;
            }
            if(ans)
                return ans;
        }
    }
    return 0;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll x, y;
    cin >> x >> y;
    string a, b;
    while(x > 0) {
        a += '0' + (x % 2);
        x /= 2;
    }
    while(y > 0) {
        b += '0' + (y % 2);
        y /= 2;
    }
    if(a == b)
        cout << "YES" << endl, exit(0);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string c = a + '1';
    while(a.back() == '0')
        a.pop_back();
    //cout << a << " " << c << " " << b << endl;
    string d = a, e = c;
    reverse(d.begin(), d.end());
    reverse(e.begin(), e.end());
    if(solve(a, b) || solve(c, b) || solve(d, b) || solve(e, b))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;   
    return 0;
}