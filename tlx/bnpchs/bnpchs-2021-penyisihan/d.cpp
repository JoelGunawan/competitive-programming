#include <bits/stdc++.h>
//#define endl "\n"
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    //FASTIO
    // use graph cycle
    int t;
    cin >> t;
    while(t--)
    {
        ll a, b, c, x, k;
        cin >> a >> b >> c >> x >> k;
        // create cycle graph of size c
        bool vis[c]; memset(vis, 0, sizeof(vis));
        // just to make handling edge cases easier
        if(k <= 100)
        {
            // brute force
            for(int i = 0; i < k; ++i)
                x = abs(a * x + b) % c;
            cout << x << endl;
            continue;
        }
        --k;
        x = abs(a * x + b) % c;
        vector<int> prev;
        while(!vis[x])
        {
            prev.pb(x);
            vis[x] = 1;
            x = abs(a * x + b) % c;
        }
        int cycle_start_index;
        for(int i = 0; i < prev.size(); ++i)
            if(prev[i] == x)
            {
                cycle_start_index = i;
                break;
            }
        vector<int> cycle(prev.size() - cycle_start_index);
        for(int i = 0; i < cycle.size(); ++i)
            cycle[i] = prev[cycle_start_index + i];
        k -= cycle_start_index;
        cout << cycle[k % cycle.size()] << endl;
    }
    return 0;
}