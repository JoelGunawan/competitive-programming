#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int h[n], maximum = 0, minimum = INT_MAX;
    ll sum = 0;
    for(int i = 0; i < n; ++i)
        cin >> h[i], maximum = max(maximum, h[i]), minimum = min(minimum, h[i]), sum += h[i];
    int q;
    cin >> q;
    if(n <= 5 * 1e3)
    {
        // use a n^2 approach
        // find what numbers exist and put them in a prefix array
        vector<vector<int>> a; vector<ll> prefix = {0}; vector<int> cur;
        minimum = INT_MAX;
        ll idx = 0, lastindex;
        while(h[idx] == 0)
            ++idx;
        lastindex = idx;
        while(sum > 0)
        {
            if(idx == n || h[idx] == 0)
            {
                prefix.push_back(minimum * (idx - lastindex) + prefix[prefix.size() - 1]);
                sum -= minimum * (idx - lastindex);
                for(int i = lastindex; i < idx; ++i)
                    h[i] -= minimum;
                minimum = INT_MAX;
                a.push_back(cur);
                cur.clear();
                idx = lastindex;
                while(h[idx] == 0)
                    ++idx;
                lastindex = idx;
            }
            cur.push_back(idx + 1);
            minimum = min(minimum, h[idx]);
            ++idx;
        }
        for(int i = 0; i < q; ++i)
        {
            ll k;
            cin >> k;
            int lower_index = (lower_bound(prefix.begin(), prefix.end(), k) - prefix.begin()); --lower_index; k -= prefix[lower_index];
            cout << a[lower_index][(k - 1) % a[lower_index].size()] << endl;
        }
    }
    else if(maximum == minimum)
    {
        for(int i = 0; i < q; ++i)
        {
            ll k;
            cin >> k;
            cout << (k - 1) % n + 1 << endl;
        }
    }
    else if((n <= 1e3 && maximum <= 1e3) || maximum <= 5)
    {
        // we can brute force this easy
        int res[n * maximum], idx = 0, cur = 0, lastindex = 0;
        while(sum > 0)
        {
            if(idx == n || h[idx] == 0)
            {
                idx = lastindex;
                while(h[idx] == 0)
                    ++idx, lastindex = idx;
            }
            --sum, res[cur++] = idx, --h[idx], ++idx;
        }
        int k;
        for(int i = 0; i < q; ++i)
            cin >> k, cout << res[k - 1] + 1 << endl;
    }
    else
    {
        // increasing sequence test case
        // use prefix sum and do a modulo
        vector<pair<ll, int>> prefix = {{0, 0}};
        ll diff = h[0]; int prev = 0;
        for(int i = 1; i < n; ++i)
        {
            if(h[i] != h[i - 1])
                prefix.push_back({diff * (n - prev) + prefix[prefix.size() - 1].first, i}), diff = h[i] - h[i - 1], prev = i;
        }
        prefix.push_back({diff * (n - prev) + prefix[prefix.size() - 1].first,prev});
        for(int i = 0; i < q; ++i)
        {
            ll k;
            cin >> k;
            pair<ll, int> a = *--lower_bound(prefix.begin(), prefix.end(), make_pair(k, 0));
            k -= a.first;
            cout << (k - 1) % (n - a.second) + a.second + 1 << endl;
        }
    }
    return 0;
}