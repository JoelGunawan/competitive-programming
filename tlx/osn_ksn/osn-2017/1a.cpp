#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string s;
    cin >> s;
    int n, dengklek, monster;
    cin >> n >> dengklek >> monster;
    vector<int> p(n - 1), l(n - 1), k(n - 1);
    for(int i = 0; i < n - 1; ++i)
        cin >> p[i] >> k[i] >> l[i];
    ll time = 0;
    multiset<int> diff;
    for(int i = 0; i < n - 1; ++i)
    {
        if(dengklek < p[i])
        {
            while(diff.size() > 0 && dengklek < p[i])
            {
                time += *diff.begin();
                ++dengklek;
                diff.erase(diff.begin());
            }
            if(dengklek < p[i])
            {
                cout << -1 << endl;
                return 0;
            }
        }
        // choose between l or k
        if(l[i] <= k[i])
        {
            ++dengklek;
            time += l[i];
        }
        else
        {
            time += k[i];
            diff.insert(l[i] - k[i]);
        }
    }
    // this is the check for the final stage
    while(dengklek < monster && diff.size() > 0)
    {
        time += *diff.begin();
        ++dengklek;
        diff.erase(diff.begin());
    }
    if(dengklek < monster)
        cout << -1 << endl;
    else
        cout << time << endl;
    return 0;
}