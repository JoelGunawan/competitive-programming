#include <bits/stdc++.h>

#define ll long long
#define dbl double
#define ldbl long double
#define v vector
#define forp(a, b) for(I i = a; i < b; ++i)
#define forn(a, b) for(I i = a; i > b; --i)
#define forpo(a) for(I i = 0; i < a; ++i)
#define forno(a) for(I i = a; i > -1; --i)
#define inputarr(a, n) forpo(n) cin >> a[i];
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
    int l, r;
    ll m;
    cin >> l >> r >> m;
    if(m < l)
    {
        cout << l << " " << l << " " << 2 * l - m << nextline;
        return;
    }
    int modulo = l, minimum = min(m % l, l - m % l);
    for(int i = l + 1; i < 2 * l && i <= r; ++i)
    {
        if(minimum > m % i || minimum > i - m % i)
        {
            minimum = min(m % i, i - m % i);
            modulo = i;
        }
    }
    cout << modulo << " ";
    if(minimum == modulo - m % modulo) cout << l << " " << l + minimum;
    else cout << l + minimum << " " << l;
    cout << nextline;
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
