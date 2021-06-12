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
    int n, m;
    cin >> n >> m;
    v<vi> a(n, vi(m));
    forpo(i, n) forpo(j, m) cin >> a[i][j];
    bool pos = 1;
    forpo(i, n) forpo(j, m)
    {
        if(!pos) break;
        // handles all diagonals
        else if(((i == 0 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1)) && a[i][j] > 2) pos = 0;
        // handles all edges but not diagonal
        else if((i == 0 || j == 0 || i == n - 1 || j == m - 1) && a[i][j] > 3) pos = 0;
        // handles the rest
        else if(a[i][j] > 4) pos = 0;
    }
    if(pos)
    {
        cout << "YES" << nextline;
        forpo(i, n)
        {
            forpo(j, m)
            {
                if((i == 0 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1)) cout << 2;
                else if(i == 0 || j == 0 || i == n - 1 || j == m - 1) cout << 3;
                else cout << 4;
                cout << " ";
            }
            cout << nextline;
        }
    }
    else cout << "NO" << nextline;
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
