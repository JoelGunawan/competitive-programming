#include <bits/stdc++.h>
 
using namespace std;
 
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<vector<int>> operations;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = 0; j < m - 1; ++j)
        {
            int onecount = (a[i][j] - '0') + (a[i][j + 1] - '0') + (a[i + 1][j] - '0') + (a[i + 1][j + 1] - '0');
            while(onecount != 0)
            {
                vector<int> tmp(6);
                if(onecount == 1)
                {
                    tmp[0] = i; tmp[1] = j; tmp[2] = i + 1; tmp[3] = j;
                    if(a[i][j] == '1') a[i][j] = '0'; else a[i][j] = '1';
                    if(a[i + 1][j] == '1') a[i + 1][j] = '0'; else a[i + 1][j] = '1';
                    if(a[i][j + 1] == '1')
                    {
                        tmp[4] = i;
                        tmp[5] = j + 1;
                        a[i][j + 1] = '0';
                    }
                    else
                    {
                        tmp[4] = i + 1;
                        tmp[5] = j + 1;
                        if(a[i + 1][j + 1] == '1') a[i + 1][j + 1] = '0'; else a[i + 1][j + 1] = '1';
                    }
                }
                else if(onecount == 2)
                {
                    int k = 1;
                    bool zero = 0;
                    if(a[i][j] == '1')
                    {
                        zero = 1;
                        a[i][j] = '0';
                    }
                    else a[i][j] = '1';
                    tmp[0] = i; tmp[1] = j;
                    if(a[i + 1][j] == '0' || !zero)
                    {
                        tmp[2 * k] = i + 1; tmp[2 * k + 1] = j;
                        if(a[i + 1][j] == '1')
                        {
                            zero = 1;
                            a[i + 1][j] = '0';
                        }
                        else a[i + 1][j] = '1';
                        ++k;
                    }
                    if(a[i][j + 1] == '0' || !zero)
                    {
                        tmp[2 * k] = i; tmp[2 * k + 1] = j + 1;
                        if(a[i][j + 1] == '1')
                        {
                            zero = 1;
                            a[i][j + 1] = '0';
                        }
                        else a[i][j + 1] = '1';
                        ++k;
                    }
                    if(a[i + 1][j + 1] == '0' || !zero)
                    {
                        tmp[2 * k] = i + 1; tmp[2 * k + 1] = j + 1;
                        if(a[i + 1][j + 1] == '1') a[i + 1][j + 1] = '0';
                        else a[i + 1][j + 1] = '1';
                    }
                }
                else if(onecount == 3)
                {
                    int k = 0;
                    if(a[i][j] != '0')
                    {
                        tmp[2 * k] = i; tmp[2 * k + 1] = j;
                        a[i][j] = '0';
                        ++k;
                    }
                    if(a[i][j + 1] != '0')
                    {
                        tmp[2 * k] = i; tmp[2 * k + 1] = j + 1;
                        ++k;
                        a[i][j + 1] = '0';
                    }
                    if(a[i + 1][j] != '0')
                    {
                        tmp[2 *k] = i + 1; tmp[2 * k + 1] = j;
                        ++k;
                        a[i + 1][j] = '0';
                    }
                    if(a[i + 1][j + 1] != '0')
                    {
                        tmp[2 *k] = i + 1; tmp[2 * k + 1] = j + 1;
                        ++k;
                        a[i + 1][j + 1] = '0';
                    }
                }
                else
                {
                    tmp[0] = i; tmp[1] = j; tmp[2] = i + 1; tmp[3] = j; tmp[4] = i; tmp[5] = j + 1;
                    a[i][j] = '0'; a[i][j + 1] = '0'; a[i + 1][j] = '0';
                }
                operations.push_back(tmp);
                onecount = (a[i][j] - '0') + (a[i][j + 1] - '0') + (a[i + 1][j] - '0') + (a[i + 1][j + 1] - '0');
            }
        }
    }
    cout << operations.size() << endl;
    for(int i = 0; i < operations.size(); ++i)
    {
        for(int j = 0; j < 6; ++j)
        {
            cout << operations[i][j] + 1 << " ";
        }
        cout << endl;
    }
}
 
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}