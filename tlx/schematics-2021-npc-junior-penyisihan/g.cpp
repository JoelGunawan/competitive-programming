#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ull unsigned long long
#define pb push_back
using namespace std;
int main()
{
    int p; ull m;
    cin >> p >> m;
    set<int> chefid;
    unordered_map<int, ull> total, lowest;
    ull c, k;
    for(int i = 0; i < p; ++i)
    {
        cin >> c >> k;
        chefid.insert(c);
        total[c] += k;
        if(lowest[c] == 0)
            lowest[c] = k;
        else
            lowest[c] = min(lowest[c], k);
    }
    multiset<ull> firstround;
    lll res = 0; ull prevchefs = 0;
    for(auto it = chefid.begin(); it != chefid.end(); ++it)
        firstround.insert(lowest[*it]);
    for(auto it = firstround.begin(); it != firstround.end(); ++it)
    {
        ++prevchefs;
        res += (*it) * prevchefs;
    }
    for(auto it = chefid.begin(); it != chefid.end(); ++it)
    {
        res += (lll)(total[*it] - lowest[*it]) * prevchefs;
        if(res >= m)
        {
            cout << "YA" << endl;
            return 0;
        }   
    }
    cout << "TIDAK" << endl;
    return 0;
}