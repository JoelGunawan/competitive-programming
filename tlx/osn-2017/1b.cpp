#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int bruteForce(int a, int k, string p, string s)
{
    if(a == k)
    {
        int res = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(p[i] == '1')
                res += (s[i] - '0');
        }
        return res;
    }
    else
    {
        int res = bruteForce(a + 1, k, p, s);
        for(int i = 0; i < s.size() - 1; ++i)
        {
            swap(s[i], s[i + 1]);
            res = max(res, bruteForce(a + 1, k, p, s));
            swap(s[i], s[i + 1]);
        }
        return res;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll n, k; string subsoal, p, s;
    cin >> subsoal >> n >> k >> p >> s;
    // k is equal to k % (n + (n + 1) / 2)
    // we can make a O(n^3) algo
    /*
    if(subsoal[1] == '1')
        cout << 25 << endl;
    else if(subsoal[2] == '2')
    {
        sort(p.begin(), p.end(), greater<int>()); int counter = 0;
        for(int i = 0; i < n; ++i)
            if(s[i] == '1')
                ++counter;
        int res = 0;
        for(int i = 0; i < counter; ++i)
            res += (p[i] - '0');
        cout << res << endl;
    }
    // we'll try to do the solution for every subproblem
    else if(subsoal[3] == '3')
        // just brute force every move k
        cout << bruteForce(0, k, s, p) << endl;
    */
    if(subsoal[4] == '4')
    {
        set<int> ones;
        for(int i = 0; i < s.size(); ++i)
            if(s[i] == '1')
                ones.insert(i);
        int res = 0;
        for(ll i = 0; i < (1 << n); ++i)
        {
            set<int> positive;
            for(ll j = 0; j < n; ++j)
                if(i & (1 << j))
                    positive.insert(j);
            if(ones.size() == positive.size())
            {
                // check whether it is possible to do such rotation in k moves
                auto it2 = positive.begin();
                int distance = 0, localres = 0;
                for(auto it = ones.begin(); it != ones.end(); ++it)
                {
                    distance += abs(*it2 - *it);
                    localres += (p[*it2] - '0');
                    ++it2;
                }
                if(k >= distance)
                    res = max(res, localres);
            }
        }
        cout << res << endl;   
    }
    else if(subsoal[6] == '6')
    {
        
    }
    return 0;
}