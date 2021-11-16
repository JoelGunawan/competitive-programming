#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll f(ll a)
{
    return a * (a + 1LL) / 2LL;
}
int main()
{
    ll n, k, q;
    cin >> n >> k >> q;
    ll a[n];
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    stack<pair<ll, ll>> s;
    ll l_child[n], r_child[n];
    // find closest greater than
    // and find the distance to closest greater than
    // r_child is distance to closest greater than on the right
    // l_child is distance to closets greater than on the left
    for(ll i = 0; i < n; ++i)
    {
        while(s.size() > 0LL && a[i] > s.top().first)
        {
            r_child[s.top().second] = i - s.top().second - 1LL;
            s.pop();
        }
        s.push({a[i], i});
    }
    while(s.size() > 0LL)
    {
        r_child[s.top().second] = n - s.top().second - 1LL;
        s.pop();
    }
    for(ll i = n - 1LL; i >= 0LL; --i)
    {
        while(s.size() > 0LL && a[i] > s.top().first)
        {
            l_child[s.top().second] = s.top().second - i - 1LL;
            s.pop();
        }
        s.push({a[i], i});
    }
    while(s.size() > 0LL)
    {
        l_child[s.top().second] = s.top().second;
        s.pop();
    }
    pair<ll, ll> heights[n];
    for(ll i = 0LL; i < n; ++i)
        heights[i] = {a[i], i};
    vector<pair<ll, ll>> arr_1(n), arr_2(n);
    ll res = 0, idx = 0;
    sort(heights, heights + n);
    for(int i = 0; i < n; ++i)
    {
        res = res + l_child[heights[i].second] * r_child[heights[i].second] + r_child[heights[i].second] + l_child[heights[i].second] + 1;
        arr_1[idx] = {(heights[i]).first + 1LL, res}, arr_2[idx] = {res, (heights[i]).first + 1LL};
        ++idx;
    }
    cout << endl;
    for(ll i = 0; i < q; ++i)
    {
        ll t, x;
        cin >> t >> x;
        if(t == 1)
        {
            // search by ketinggian
            auto it = lower_bound(arr_1.begin(), arr_1.end(), make_pair(x - k * i, (ll)1e18));
            if(it == arr_1.begin())
                cout << 0 << endl;
            else
            {
                --it;
                cout << (*it).second << endl;
            }
        }
        else
        {
            auto it = lower_bound(arr_2.begin(), arr_2.end(), make_pair(x, (ll)-1e18));
            if(x == 0)
                cout << 1 << endl;
            else if(it == arr_2.end())
                cout << -1 << endl;
            else
                cout << (*it).second + k * i << endl;
        }
    }
    return 0;
}