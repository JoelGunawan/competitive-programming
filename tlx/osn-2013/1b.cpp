#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    string subsoal; int n;
    cin >> subsoal >> subsoal >> n;
    vector<tuple<int, int, int, int>> a(n);
    for(int i = 0; i < n; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = make_tuple(x, y, z, i + 1);
    }
    sort(a.begin(), a.end());
    bool used[n];
    memset(used, 0, sizeof(bool) * (n));
    vector<int> numbers;
    for(int i = 0; i < n; ++i)
        for(int j = n - 1; j >= 0; --j)
        {
            if(!used[j] && (upper_bound(numbers.begin(), numbers.end(), get<0>(a[j])) - numbers.begin()) >= get<1>(a[j]))
            {
                cout << get<3>(a[j]) << " ";
                numbers.push_back(get<0>(a[j]));
                used[j] = 1;
                break;
            }
        }
    return 0;
}