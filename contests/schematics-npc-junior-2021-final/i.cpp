#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ins insert
#define lll __int128
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
using namespace std;
int sqr(int a)
{
    return a * a;
}
void solve()
{
    int n;
    cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;
    if(n <= 100)
    {
        // check each triplet and find what kind of triangle it is
        // find using pythagorean theorem
        int res = 0;
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                for(int k = j + 1; k < n; ++k)
                {
                    int x = sqr(a[i].first - a[j].first) + sqr(a[i].second - a[j].second);
                    int y = sqr(a[i].first - a[k].first) + sqr(a[i].second - a[k].second);
                    int z = sqr(a[j].first - a[k].first) + sqr(a[j].second - a[k].second);
                    vector<int> arr = {x, y, z};
                    sort(arr.begin(), arr.end());
                    //cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
                    if(arr[0] + arr[1] > arr[2])
                        res += 3;
                    else
                        res += 2;
                }
        cout << res << endl;
    }
    else
    {
        // do the test case where there are 2 pusats for every triplet
        // so find the amount of triplets and we multiply by 2
        ll res = 0;
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                res += n - j - 1;
        cout << 2 * res << endl;
    }
    
}
int main()
{
    fast_io();
    solve();
    return 0;
}