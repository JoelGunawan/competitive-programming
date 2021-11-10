#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
int main()
{
    fast_io();
    // O(nq)
    // subtask 1, 2, 4, 5
    /*
    int n;
    cin >> n;
    int h[n + 1];
    for(int i = 1; i <= n; ++i)  
        cin >> h[i];
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i)
    {
        int s, t;
        cin >> s >> t;
        if(s < t)
        {
            // find max height between s and t
            int max_height = 0;
            for(int j = s; j <= t; ++j)
                max_height = max(max_height, h[j]);
            // increase from s to max height
            int idx = s, cur_height = h[s];
            ll res = 0;
            while(h[idx] < max_height && cur_height < max_height)
            {
                ++idx;
                ++cur_height, res += 4;
                if(cur_height < h[idx])
                    res += (ll)(h[idx] - cur_height) * 4, cur_height = h[idx];
            }
            while(h[idx] < max_height)
                res += 2, ++idx;
            // go from right to left, trying to get to max height in the most optimal way
            // but if we need to go up we add 1 instead of 4, lateral movement is valued at 2
            int idx_2 = t;
            cur_height = h[t];
            while(h[idx_2] < max_height && cur_height < max_height)
            {
                --idx_2;
                ++cur_height, ++res;
                if(cur_height < h[idx_2])
                    res += (h[idx_2] - cur_height), cur_height = h[idx_2];
            }
            while(idx_2 != idx)
                --idx_2, res += 2;
            cout << res << endl;
        }
        else
        {
            // find max height between s and t
            int max_height = 0;
            for(int j = s; j >= t; --j)
                max_height = max(max_height, h[j]);
            // increase from s to max height
            int idx = s, cur_height = h[s];
            ll res = 0;
            while(h[idx] < max_height && cur_height < max_height)
            {
                --idx;
                ++cur_height, res += 4;
                if(cur_height < h[idx])
                    res += (ll)(h[idx] - cur_height) * 4, cur_height = h[idx];
            }
            while(h[idx] < max_height)
                res += 2, --idx;
            // go from right to left, trying to get to max height in the most optimal way
            // but if we need to go up we add 1 instead of 4, lateral movement is valued at 2
            int idx_2 = t;
            cur_height = h[t];
            while(h[idx_2] < max_height && cur_height < max_height)
            {
                ++idx_2;
                ++cur_height, ++res;
                if(cur_height < h[idx_2])
                    res += (h[idx_2] - cur_height), cur_height = h[idx_2];
            }
            while(idx_2 != idx)
                ++idx_2, res += 2;
            cout << res << endl;
        }
    }
    */
    // subtask 3
    /*
    int n;
    cin >> n;
    int h[n];
    for(int i = 0; i < n; ++i)
        cin >> h[i];
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i)
    {
        int s, t;
        cin >> s >> t;
        if(s < t)
            cout << 4 * (t - s) << endl;
        else
            cout << s - t << endl;
    }
    */
    // subtask 6
    int n;
    cin >> n;
    int h[n];
    for(int i = 0; i < n; ++i)
        cin >> h[i];
    
    return 0;
}