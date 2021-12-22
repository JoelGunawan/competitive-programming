#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll arr[262144];
int n, m;

ll findM(ll x)
{
    ll result = 0;
    for(int i = 0; i < n; ++i)
    {
        result += (x / arr[i]);
        if(result > m) return result;
    }
    return result;
}

ll findLowerBound(int m, ll lowerbound, ll upperbound)
{
    ll ans = -1;
    while(lowerbound <= upperbound)
    {
        ll mid = (lowerbound + upperbound) / 2;
        ll curm = findM(mid);
        if(curm == m)
        {
            ans = mid;
            upperbound = mid - 1;
        }
        else if(curm > m)
        {
            upperbound = mid - 1;
        }
        else
        {
            lowerbound = mid + 1;
        }
    }
    return ans;
}

ll findUpperBound(int m, ll lowerbound, ll upperbound)
{
    ll ans = -1;
    while(lowerbound <= upperbound)
    {
        ll mid = (lowerbound + upperbound) / 2;
        ll curm = findM(mid);
        if(curm == m)
        {
            ans = mid;
            lowerbound = mid + 1;
        }
        else if(curm > m)
        {
            upperbound = mid - 1;
        }
        else
        {
            lowerbound = mid + 1;
        }
    }
    return ans;
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    ll lowerbound = 0, upperbound = (unsigned long long)pow(2, 62) - 1;
    int upperBound = findUpperBound(m, lowerbound, upperbound)
    , lowerBound = findLowerBound(m, lowerbound, upperbound);
    if(lowerBound == -1 || upperBound == -1)
    {
        cout << 0 << endl;
    }
    else cout << upperBound - lowerBound + 1 << endl;
}