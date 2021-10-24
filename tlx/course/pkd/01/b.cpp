#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r, c;
    char input;
    cin >> r >> c;
    int a[r][c];
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            cin >> input, a[i][j] = input - '0';
    bool ans = 1;
    while(ans)
    {
        int lowest_runtuh = -1;
        ans = 0;
        for(int i = 0; i < r; ++i)
        {
            bool tmp = 1;
            for(int j = 0; j < c; ++j)
                if(!a[i][j])
                    tmp = 0;
            if(tmp)
            {
                for(int j = 0; j < c; ++j)
                    a[i][j] = 0;
                ans = 1, lowest_runtuh = i;
            }
        }
        if(lowest_runtuh == -1)
            break;
        int cur_height[c];
        for(int i = 0; i < c; ++i)
            cur_height[i] = r - 1;
        for(int i = 0; i < c; ++i)
            for(int j = r - 1; j > lowest_runtuh; --j)
                if(a[j][i])
                    cur_height[i] = j - 1;
        
        for(int i = lowest_runtuh; i >= 0; --i)
            for(int j = 0; j < c; ++j)
                if(a[i][j])
                {
                    a[i][j] = 0;
                    a[cur_height[j]--][j] = 1;
                }
    }
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
            cout << a[i][j];
        cout << endl;
    }
    return 0;
}