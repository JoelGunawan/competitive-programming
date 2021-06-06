#include <iostream>

using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a >= 4 && b >= 4 && c >= 4)
    {
        cout << 7 << endl;
        return;
    }
    if(a == 0 && b == 0 && c == 0)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        int result = 0;
        if(a > 0)
        {
            ++result;
            --a;
        }
        if(b > 0)
        {
            ++result;
            --b;
        }
        if(c > 0)
        {
            ++result;
            --c;
        }
        if(a >= b && a >= c)
        {
            if(a > 0 && b > 0)
            {
                --a;
                --b;
                ++result;
            }
            if(a > 0 && c > 0)
            {
                --a;
                --c;
                ++result;
            }
            if(b > 0 && c > 0)
            {
                --b;
                --c;
                ++result;
            }
        }
        else if(b >= a && b >= c)
        {

            if(a > 0 && b > 0)
            {
                --a;
                --b;
                ++result;
            }
            if(b > 0 && c > 0)
            {
                --b;
                --c;
                ++result;
            }
            if(a > 0 && c > 0)
            {
                --a;
                --c;
                ++result;
            }
        }
        else
        {
            if(b > 0 && c > 0)
            {
                --b;
                --c;
                ++result;
            }
            if(a > 0 && c > 0)
            {
                --a;
                --c;
                ++result;
            }
            if(a > 0 && b > 0)
            {
                --a;
                --b;
                ++result;
            }
        }
        if(a > 0 && b > 0 && c > 0)
        {
            ++result;
            --a;
            --b;
            --c;
        }
        cout << result << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
