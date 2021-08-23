#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int k;
        cin >> k;
        int res = 0;
        for(int i = 0; i < k; ++i)
        {
            ++res;
            while(res % 3 == 0 || res % 10 == 3)
                ++res;
        }
        cout << res << endl;
    }
}