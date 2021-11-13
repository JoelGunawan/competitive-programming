#include <bits/stdc++.h>
#define ll long logn
using namespace std;
int main()
{
    int q, k;
    cin >> q >> k;
    for(int i = 0; i < q; ++i)
    {
        int c;
        cin >> c;
        bool ans = 1;
        int res = 0;
        for(int j = 0; j < 30; ++j)
        {
            if(!((1 << j) & c) && ((1 << j) & k))
                ans = 0;
            else if((1 << j) & c)
                res += (1 << j);
        }
        if(ans)
            cout << res << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}