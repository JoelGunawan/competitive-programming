#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    multiset<ll> array; ll diff = 0;
    while(q--)
    {
        int type;
        cin >> type;
        if(type == 3)
        {
            cout << *array.begin() + diff << endl;
            array.erase(array.begin());
        }
        else
        {
            int x;
            cin >> x;
            if(type == 1)
                array.insert(x - diff);
            else
                diff += x;
        }
    }
    return 0;
}