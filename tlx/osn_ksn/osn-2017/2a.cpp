#include <bits/stdc++.h>
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    string subsoal; int n, k;
    cin >> subsoal >> n >> k;
    // we need to maintain 2 multisets
    // first is the sorted, second is the current actual
    // if both are the same, then that is one "segment"
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> b = a;
    sort(b.begin(), b.end());
    int res = 0, streak = 0, diff = 0;
    map<int, int> required, currents;
    multiset<int> betweens;
    for(int i = 0; i < n; ++i)
    {
        // check for streaks of sorted and of not sorted
        if(required[a[i]] == currents[a[i]])
            ++diff;
        ++required[a[i]];
        if(required[a[i]] == currents[a[i]])
            --diff;
        if(required[b[i]] == currents[b[i]])
            ++diff;
        ++currents[b[i]];
        if(required[b[i]] == currents[b[i]])
            --diff;
        if(diff == 0)
        {
            required.clear();
            currents.clear();
            ++streak;
        }
        else
        {
            if(streak != 0 && streak != i)
                betweens.insert(-streak);
            streak = 0;
            ++res;
        }
    }
    for(int i = 0; i < k - 1; ++i) {
        if(betweens.size() == 0)
            break;
        else
            betweens.erase(betweens.begin());
    }
    for(auto it = betweens.begin(); it != betweens.end(); ++it)
        res += -(*it);
    cout << k + res << endl;
}