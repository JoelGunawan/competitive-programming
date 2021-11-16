#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
int mod = 1e6 + 7;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T, n, a[100], t, counter;
    pair<int, int> pairs[100];
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        for(int i = 0; i < n; ++i)
            scanf("%d", &t), pairs[i] = {a[i], -t};
        sort(pairs, pairs + n);
        set<int> heights;
        t = 0, counter = 0;
        for(int i = 0; i < n; ++i)
        { 
            if(heights.lower_bound(pairs[i].second) != heights.end())
                heights.erase(heights.lower_bound(pairs[i].second));
            heights.insert(pairs[i].second);
        }
        cout << heights.size() << endl;
    }
    return 0;
}