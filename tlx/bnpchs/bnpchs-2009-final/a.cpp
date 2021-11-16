#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    // generate all fib number below int_max
    vector<int> f, g;
    unsigned ll sum = 0, a = 1, b = 0;
    while(sum <= INT_MAX)
    {
        f.push_back(sum);
        g.push_back(a);
        sum += a;
        ll tmp = a;
        a += b, b = tmp;
    }
    int t;
    cin >> t;
    while(t--)
    {
        int num;
        char x, y;
        cin >> x >> y >> num;
        int startnumberindex = distance(f.begin(), --upper_bound(f.begin(), f.end(), num)), index = num - f[startnumberindex];   
        while(startnumberindex > 1)
        {
            if(g[startnumberindex - 1] <= index)
                index -= g[startnumberindex - 1], startnumberindex = startnumberindex - 2;
            else
                --startnumberindex;
        }
        if(startnumberindex)
            cout << y;
        else
            cout << x;
        cout << endl;
    }
}