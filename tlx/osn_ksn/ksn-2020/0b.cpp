#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> solve(ll n)
{
    for(ll i = sqrt(n); i >= 0 && i >= sqrt(n) - 50; --i)
        for(ll j = sqrt(n - i * i); j >= 0 && j >= sqrt(n - i * i) - 50; --j)
            for(ll k = sqrt(n - i * i - j * j); k >= 0 && k >= sqrt(n - i * i - j * j) - 50; --k)
                for(ll l = sqrt(n - k * k - i * i - j * j); l >= 0 && l >= sqrt(n - i * i - j * j - k * k) - 50; --l)
                    if(i * i + j * j + k * k + l * l == n)
                        return {i, j, k, l};
    return {-1, -1, -1, -1};
}
int main()
{
    ifstream fin; ofstream fout;
    for(int i = 1; i <= 10; ++i)
    {
        fin.open("./inputs/empat_" + to_string(i) + ".in");
        ll n;
        fin >> n;
        fin.close();
        vector<ll> a = solve(n);
        fout.open("./outputs/empat_" + to_string(i) + ".out");
        for(int i = 0; i < 4; ++i)
            fout << a[i] << " ";
        fout.close();
    }
    return 0;
}