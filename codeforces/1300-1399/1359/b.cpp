#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int a = 0, b = 0;
    for(int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        for(int j = 1; j < m; ++j)
        {
            if(s[j] == s[j - 1] && s[j] == '.')
            {
                ++a;
                ++j;
            }
        }
        for(int j = 0; j < m; ++j)
        {
            if(s[j] == '.') ++b;
        }
    }
    if(2 * x <= y)
    {
        cout << b * x << endl;
    }
    else
    {
        cout << (b - 2 * a) * x + a * y << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
