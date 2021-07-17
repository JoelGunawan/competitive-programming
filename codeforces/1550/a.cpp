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
        int s;
        cin >> s;
        int res = 0, inc = 1;
        while(res < s)
        {
            res += inc;
            inc += 2;
        }
        cout << inc / 2 << endl;
    }
    return 0;
}