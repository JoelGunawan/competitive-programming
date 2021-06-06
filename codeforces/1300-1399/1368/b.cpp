#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll limit = 1e16;

int main()
{
    const string str = "codeforces";
    int strlen = str.size();
    // find 8 factors with the lowest possible sum
    ll n;
    cin >> n;
    vector<ll> bounds(1, 0);
    while(bounds[bounds.size() - 1] < limit)
    {
        ll res = 1, mul = bounds.size();
        for(int i = 0; i < 10; ++i)
            res *= mul;
        bounds.push_back(res);
    }
    int start = --lower_bound(bounds.begin(), bounds.end(), n) - bounds.begin();
    vector<ll> result(strlen, start);
    ll res = 1;
    for(int i = 0; i < strlen; ++i)
        res *= result[i];
    int k = 0;
    while(res < n)
    {
        ++result[k];
        res = 1;
        for(int i= 0; i < strlen; ++i)
            res *= result[i];
        ++k;
    }
    for(int i = 0; i < strlen; ++i)
        for(int j = 0; j < result[i]; ++j)
            cout << str[i];
    return 0;
}
