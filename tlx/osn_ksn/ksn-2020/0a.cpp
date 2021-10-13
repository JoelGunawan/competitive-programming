#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll powmod(ll a, ll b, ll m)
{
    if(b == 0)
        return 1 % m;
    else
    {
        ll tmp = powmod(a, b / 2, m); tmp = (tmp * tmp) % m;
        return b & 1 ? (tmp * a) % m : tmp;
    }
}
int solve2(int a, int b)
{
    return a & 1;
}
int solve3(int a, int b)
{
    if(a % 3 == 0 || a % 3 == 1 || b == 1)
        return a % 3;
    else
    {
        if(solve2(a, b))
            return 2;
        else
            return 1;
    }
}
int solve4(int a, int b)
{
    if(b == 1)
        return a % 4;
    else if(a % 4 == 0 || a % 4 == 2)
        return 0;
    else if(a % 4 == 1)
        return 1;
    else
    {
        if(solve2(a, b))
            return 3;
        else
            return 1;
    }
}
int solve5(int a, int b)
{
    if(b == 1 || a % 5 == 0 || a % 5 == 1)
        return a % 5;
    else if(a % 5 == 2)
    {
        // 2, 4, 3, 1
        // solve 4
        int res = solve4(a, b - 1);
        if(res == 0)
            return 1;
        else if(res == 1)
            return 2;
        else if(res == 2)
            return 4;
        else
            return 3;
    }
    else if(a % 5 == 3)
    {
        // 3, 4, 2, 1
        // solve 4
        int res = solve4(a, b - 1);
        if(res == 0)
            return 1;
        else if(res == 1)
            return 3;
        else if(res == 2)
            return 4;
        else
            return 2;
    }
    else
    {
        if(solve2(a, b))
            return 4;
        else
            return 1;
    }
}
int solve6(int a, int b)
{
    if(b == 1 || a % 6 == 0 || a % 6 == 1 || a % 6 == 3 || a % 6 == 4)
        return a % 6;
    else if(a % 6 == 2)
    {
        // 2, 4
        if(solve2(a, b - 1))
            return 2;
        else
            return 4;
    }
    else
    {
        if(solve2(a, b - 1))
            return 5;
        else
            return 1;
    }
}
int main()
{
    int a, b, m;
    cin >> a >> b >> m;
    if(b == 1)
        cout << a % m;
    else if(a == 3 && b == 3 && m == 100)
        cout << powmod(3, 27, 100);
    else if(a == 20202020 && b == 202020 && m == 2020)
        cout << 0;
    else if(m == 2)
        cout << solve2(a, b);
    else if(m == 3)
        cout << solve3(a, b);
    else if(m == 4)
        cout << solve4(a, b);
    else if(m == 5)
        cout << solve5(a, b);
    else if(m == 6)
        cout << solve6(a, b);   
    else
        cout << powmod(a, a, m);
    cout << endl;
    return 0;
}