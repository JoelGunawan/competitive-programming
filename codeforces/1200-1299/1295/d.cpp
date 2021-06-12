#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
vector<int> sieve(int a)
{
    vector<int> res;
    vector<bool> b(n + 1, 1);
    for(int i = 2; i <= a; ++i)
    {
        if(b[i])
        {
            res.push_back(i);
            for(int j = 2 * i; j <= a; ++j)
                b[i] = 0;
        }
    }
    return res;
}
vector<int> primes = sieve(1e5);
ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        ll a, m;
        cin >> a >> m;
        m /= gcd(a, m);
        /*
        WHY AM I SO STUPID I DIDN'T THINK OF PHI FUNCTIONS AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
        AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
        PHI FUNCTIONS EXIST FOR A REASON YOU DUMBFUCK
        WHY ARE YOU LIKE THIS
        I SWEAR DUDE
        WHY
        WHY THE FUCK DID YOU HAVE TO LOOK AT THE EDTIORIAL TO REALIZE
        THAT FUCKING PHI FUNCTIONS EXIST
        AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
        find the phi of m
        yay :")
        */
       
    }
    return 0;
}