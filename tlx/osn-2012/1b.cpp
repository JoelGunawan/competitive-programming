#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    cin >> s >> s;
    int n;
    cin >> n;
    vector<int> x(n); vector<vector<int>> a(n, vector<int>(n)), b;
    for(int i = 0; i < n; ++i)
        cin >> x[i];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> a[i][j];
    bool possible = 1, allzero = 1;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(a[i][j])
                allzero = 0;
            if(a[i][j] && !x[i] && !x[j])
                possible = 0;
        }
    }
    b = a;
    if(!possible)
    {
        cout << -1 << endl;
        return 0;
    }
    else if(allzero)
    {
        cout << 0 << endl;
        return 0;
    }
    int first;
    for(int i = 0; i < n; ++i)
        if(x[i])
        {
            first = i;
            break;
        }
    int res1 = 0, res2 = 0;
    // do vertical with first then horizontal
    for(int i = 0; i < n; ++i)
    {
        if(a[first][i])
        {
            for(int j = 0; j < n; ++j)
                a[j][i] ^= x[j];
            ++res1;
        }
    }
    for(int i = 0; i < n; ++i)
    {
        // if there is a one do xor
        for(int j = 0; j < n; ++j)
        {
            if(a[i][j])
            {
                for(int k = 0; k < n; ++k)
                    a[i][k] ^= x[k];
                ++res1;
                break;
            }
        }
    }
    for(int i = 0; i < n; ++i)
    {
        if(b[i][first])
        {
            for(int j = 0; j < n; ++j)
                b[i][j] ^= x[j];
            ++res2;
        }
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(b[j][i])
            {
                for(int k = 0; k < n; ++k)
                    b[k][i] ^= x[k];
                ++res2;
                break;
            }
        }
    }
    bool pos1 = 1, pos2 = 1;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(a[i][j])
                pos1 = 0;
            if(b[i][j])
                pos2 = 0;
        }
    }
    if(pos1 & pos2)
        cout << min(res1, res2) << endl;
    else if(pos1)
        cout << res1 << endl;
    else if(pos2)
        cout << res2 << endl;
    else
        cout << -1 << endl;
    return 0;
}