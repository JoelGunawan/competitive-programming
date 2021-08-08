#include <bits/stdc++.h>
#define endl "\n"
#define rll register int_fast64_t
#define rint register int_fast32_t
#define v vector
#define pb push_back
#define ins insert
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
int a[(int)(3 * 1e5)], t[(int)(3 * 1e5)];
void test_case()
{
    rint n, k;
    cin >> n >> k;
    for(int i = 0; i < k; ++i)
        cin >> a[i];
    for(int i = 0; i < k; ++i)
        cin >> t[i];
    set<pair<int, int>> possort, tempsort;
    for(int i = 0; i < k; ++i)
    {
        tempsort.insert(make_pair(t[i], a[i]));
        possort.insert(make_pair(a[i], t[i]));
    }
    while(tempsort.size() > 0)
    {
        pair<int, int> cur = *tempsort.begin();
        swap(cur.first, cur.second);
        auto it1 = possort.find(cur), it2 = it1;
        // go up and go down trying to delete
        ++it1;
        while(it1 != possort.end() && abs((*it1).first - cur.first) + cur.second <= (*it1).second)
        {
            pair<int, int> tmp = *it1;
            ++it1;
            possort.erase(tmp);
            swap(tmp.first, tmp.second);
            tempsort.erase(tmp);
        }
        if(it2 == possort.begin())
        {
            tempsort.erase(tempsort.begin());
            continue;
        }
        --it2;
        while(it2 != possort.begin() && abs((*it2).first - cur.first) + cur.second <= (*it2).second)
        {
            pair<int, int> tmp = *it2;
            --it2;
            possort.erase(tmp);
            swap(tmp.first, tmp.second);
            tempsort.erase(tmp);
        }
        if(abs((*it2).first - cur.first) + cur.second <= (*it2).second)
        {
            pair<int, int> tmp = *it2;
            possort.erase(tmp);
            swap(tmp.first, tmp.second);
            tempsort.erase(tmp);
        }
        tempsort.erase(tempsort.begin());
    }
    auto it1 = possort.begin(), it2 = it1;
    if(possort.size() != 1)
        ++it2;
    for(int i = 0; i < n; ++i)
    {
        // find the minimum between it1 and it2
        //cout << (*it1).first << " " << (*it1).second << " " << (*it2).first << " " << (*it2).second << endl;
        cout << min(abs(i + 1 - (*it1).first) + (*it1).second, abs(i + 1 - (*it2).first) + (*it2).second) << " ";
        auto tmp = it2; ++tmp;
        if(abs(i + 1 - (*it2).first) + (*it2).second < abs(i + 1 - (*it1).first) + (*it1).second && tmp != possort.end())
        {
            ++it1;
            ++it2;
        }
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q;
    cin >> q;
    while(q--)
        test_case();
    return 0;
}