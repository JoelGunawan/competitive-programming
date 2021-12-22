#include<bits/stdc++.h>
using namespace std;
bool addzero = false;
const int MOD = 1e6;

void checkexponent(int a, int b)
{
    if(a >= MOD)
    {
        addzero = true;
        return;
    }
    long long int result = 1;
    for(int i = 0; i < b; i++)
    {
        result *= a;
        if(result >= MOD)
        {
            addzero = true;
            return;
        }
    }
}

long long int exponentmod(int a, int b)
{
    if(b == 0) return 1;
    if(b == 1) return a;
    else if(b % 2 == 1) return (a *
        (exponentmod(a, b / 2) % MOD) * (exponentmod(a, b / 2) % MOD)) % MOD;
    else return ((exponentmod(a, b / 2) % MOD) * (exponentmod(a, b / 2) % MOD)) % MOD;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    checkexponent(a, b);
    a %= MOD;
    int expmod = exponentmod(a, b);
    string result = to_string(expmod);
    if(addzero)
    {
        while(result.length() < 6)
        {
            result.insert(result.begin(), '0');
        }
    }
    printf("%s\n", result.c_str());
}