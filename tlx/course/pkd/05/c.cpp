#include<bits/stdc++.h>
using namespace std;
long long int MOD;

long long int exponentmod(long long int a, long long int b)
{
    if(b == 0) return 1;
    else if(b == 1) return a % MOD;
    else if(b % 2 == 1)
    {
        return (a * (exponentmod(a, b - 1) % MOD)) % MOD;
    }
    else
    {
        long long int temp = exponentmod(a, b / 2) % MOD;
        return (temp * temp) % MOD;
    }
}

long long int specialexponent(long long int a, long long int b, long long int c)
{
    if(b == 0) return 1;
    else if(c == 0) return a % MOD;
    else if(c == 1 || b == 1) return exponentmod(a, b);

    long long int cur = exponentmod(a, b);
    for(int i = 1; i < c; i++)
    {
        cur = exponentmod(cur, b);
    }
    return cur;
}

int main()
{
    long long int a, b, c;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &MOD);
    long long int result = specialexponent(a, b, c) + 1;
    printf("%lld\n", result);
    return 0;
}
