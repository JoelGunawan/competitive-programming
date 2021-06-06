#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    int res = 0;
    // equalize
    if(a != b)
    {
        int diff = abs(a - b), low = min(a, b), high = max(a, b);
        int subtract = min(diff, min(low, high / 2));
        low -= subtract;
        high -= (subtract * 2);
        if(a < b)
        {
            a = low;
            b = high;
        }
        else
        {
            a = high;
            b = low;
        }
        res += subtract;
    }
    // divi by 3
    // guaranteed to be equalized if it is bigger than 3
    if(a >= 3 && b >= 3)
    {
        res += min(a / 3, b / 3) * 2;
        int subtract = min(a / 3, b / 3) * 3;
        a -= subtract;
        b -= subtract;
    }
    // when less than 3
    if(a >= 1 && b > 1)
    {
        ++res;
        b -= 2;
        --a;
    }
    if(a > 1 && b >= 1)
    {
        ++res;
        --b;
        a -= 2;
    }
    cout << res << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
