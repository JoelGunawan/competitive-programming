#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#pragma GCC optimize("Ofast")
using namespace std;
void test_case()
{
    int n;
    cin >> n;
    // when we select a number, we are basically limiting how much we can choose as min(a, i) + min(b, n - i - 1)
    // we need to select a combination such that it maintains the largest number
    // we can probably greedy this?
    // or we can sort this
    // implement bitmask to find pattern
    // do a 2 way dp, where there is front and back, we find the max such that we 
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    int left = 1, right = n, res = 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        //cout << mid << endl;
        // try to construct the solution for mid
        int x = mid - 1, y = 0, cnt = 0;
        for(int i = 0; i < n; ++i)
        {
            //cout << x << " " << y << " " << a[i].fi << " " << a[i].se << endl;
            if(a[i].fi >= x && a[i].se >= y)
                --x, ++y, ++cnt;
            if(x < 0)
                break;
        }
        if(cnt == mid)
            res = mid, left = mid + 1;
        else
            right = mid - 1;
    }
    cout << res << endl;
    //cout << "BREAK" << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}