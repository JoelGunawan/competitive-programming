#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        char odd = 0, even = 0;
        bool possible = 1;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
            {
                if(a[i][j] == 'R' || a[i][j] == 'W')
                {
                    if((i + j) & 1)
                    {
                        if(!odd)
                        {
                            odd = a[i][j];
                            if(odd == 'R')
                                even = 'W';
                            else
                                even = 'R';
                        }
                        else if(odd && a[i][j] != odd)
                            possible = 0;
                    }
                    else
                    {
                        if(!odd)
                        {
                            even = a[i][j];
                            if(even == 'R')
                                odd = 'W';
                            else
                                odd = 'R';
                        }
                        else if(odd && a[i][j] != even)
                            possible = 0;
                    }
                }
            }
        if(odd == 0)
        {
            odd = 'R';
            even = 'W';
        }
        if(possible)
        {
            cout << "YES" << endl;
            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < m; ++j)
                {
                    if((i + j) & 1)
                        cout << odd;
                    else
                        cout << even;
                }
                cout << endl;
            }
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}