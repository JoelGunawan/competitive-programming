#include <bits/stdc++.h>
using namespace std;
int main()
{
    int price[4];
    price[0] = 0;
    cin >> price[1] >> price[2] >> price[3];
    pair<int, int> a[3];
    for(int i = 0; i < 3; ++i)
        cin >> a[i].first >> a[i].second;
    int counter[101]; memset(counter, 0, sizeof(counter));
    for(int i = 0; i < 3; ++i)
    {
        for(int j = a[i].first; j < a[i].second; ++j)
            ++counter[j];
    }
    int res = 0;
    price[2] *= 2, price[3] *= 3;
    for(int i = 0; i <= 100; ++i)
        res += price[counter[i]];
    cout << res << endl;
    return 0;
}