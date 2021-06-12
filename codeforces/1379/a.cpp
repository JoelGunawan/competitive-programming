#include <bits/stdc++.h>

#define ll long long
#define dbl double
#define ldbl long double
#define v vector
#define forp(i, a, b) for(int i = a; i < b; ++i)
#define forn(i, a, b) for(int i = a; i > b; --i)
#define forpo(i, a) for(int i = 0; i < a; ++i)
#define forno(i, a) for(int i = a; i > -1; --i)
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
const int targetlen = 7;
const str targetstring = "abacaba";

bool possibleToConvert(str s)
{
    forpo(i, targetlen) if(s[i] != targetstring[i] && s[i] != '?') return false;
    return true;
}

void solve()
{
    int n; str s;
    cin >> n >> s;
    int base = 0;
    forpo(i, n - 6) if(s.substr(i, targetlen) == targetstring) ++base;
    if(base == 1)
    {
        // change all question marks to z
        cout << "Yes" << nextline;
        forpo(i, s.size()) if(s[i] == '?') s[i] = 'z';
        cout << s << nextline;
    }
    else if(base > 1) cout << "No" << nextline;
    else
    {
        forpo(i, n - 6) if(possibleToConvert(s.substr(i, targetlen)))
        {
            bool ans = 1;
            str tmp = s;
            forp(j, i, i + targetlen) tmp[j] = targetstring[j - i];
            forpo(j, n - 6) if(j != i && tmp.substr(j, targetlen) == targetstring) ans = 0;
            if(ans)
            {
                forpo(j, n) if(tmp[j] == '?') tmp[j] = 'z';
                cout << "Yes" << nextline;
                cout << tmp << nextline;
                return;
            }
        }
        cout << "No" << nextline;
    }
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
