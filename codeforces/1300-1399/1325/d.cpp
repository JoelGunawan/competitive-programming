#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll u, v;
    cin >> u >> v;
    if(u == 0 && v == 0)
        cout << 0 << endl;
    else if(u > v || ((v - u) & 1) || v == 0)
        cout << -1 << endl;
    else
    {
        v -= u;
        vector<ll> num;
        num.push_back(u);
        ll tmp = 1LL << 62;
        while(tmp > 1)
        {
            if(tmp & v)
            {
                v -= tmp;
                // iterate through each number and check if we can add to it
                int remain = 2;
                for(int i = 0; i < num.size(); ++i)
                {
                    if(remain > 0 && !(num[i] & (tmp / 2)))
                    {
                        --remain;
                        num[i] += (tmp / 2);
                    }
                }
                for(int i = 0; i < remain; ++i)
                    num.push_back(tmp / 2);
            }
            tmp /= 2;
        }
        cout << num.size() << endl;
        for(auto it = num.begin(); it != num.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    return 0;
}