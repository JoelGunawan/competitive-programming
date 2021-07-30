#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> r(n, vector<int>(5));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < 5; ++j)
                cin >> r[i][j];
        int index = 0, local = 0;
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < 5; ++j)
            {
                if(r[i][j] < r[index][j])
                    ++local;
            }
            if(local >= 3)
                index = i;
            local = 0;
        }
        bool ans = 1;
        for(int i = 0; i < n; ++i)
        {
            if(i == index)
                continue;
            for(int j = 0; j < 5; ++j)
            {
                if(r[i][j] < r[index][j])
                    ++local;
            }
            if(local >= 3)
                ans = 0;
            local = 0;
        }
        if(ans)
            cout << index + 1 << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}