#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
bool isPowerOf2(int n)
{
    long long a = 1, b = n;
    while(a < b)
    {
        a *= 2;
        if(a == b)
            return 1;
    }
    return 0;
}
int logarithm2(int n)
{
    long long a = 1; int num = 0;
    while(a != n)
    {
        if(a == n)
            return num;
        ++num;
        a *= 2;
    }
    return num;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        // the player that gets prime or 1 loses
        if((n & 1) || (isPowerOf2(n) && (logarithm2(n) & 1)))
            cout << "Bob" << endl;
        else
            cout << "Alice" << endl;
    }
    return 0;
}