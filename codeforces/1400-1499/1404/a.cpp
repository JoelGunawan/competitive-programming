#include <bits/stdc++.h>
 
#define ll long long
#define dbl double
#define ldbl long double
#define v vector
#define forp(i, a, b) for(int i = a; i < b; ++i)
#define forn(i, a, b) for(int i = a; i > b; --i)
#define forpo(i, a) for(int i = 0; i < a; ++i)
#define forno(i, a) for(int i = a; i > -1; --i)
#define inputarr(a, n) forpo(i, n) cin >> a[i];
#define vi vector<int>
#define vs vector<string>
#define str string
#define pb push_back
#define ull unsigned long long
#define nextline "\n"
#define TEST cout << "TEST" << endl;
 
using namespace std;
 
int mod = 1e9 + 7;
 
void solve()
{
    int n, k; str s;
    cin >> n >> k >> s;
    str res = "";
    bool hasans = 1;
    forpo(i, k)
    {
        char a = '?';
        int j = i;
        while(j < n)
        {
            if(a != '?' && a != s[j] && s[j] != '?') hasans = 0;
            else if(a == '?' && a != s[j]) a = s[j];
            j += k;
        }
        res += a;
    }
    int one = 0, zero = 0;
    forpo(i, k)
    {
        if(res[i] == '0') ++zero;
        else if(res[i] == '1') ++one;
    }
    if(zero > k / 2 || one > k / 2 || !hasans) cout << "NO" << nextline;
    else cout << "YES" << nextline;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    cout << fixed << setprecision(15);
    while(t--) solve();
    return 0;
}