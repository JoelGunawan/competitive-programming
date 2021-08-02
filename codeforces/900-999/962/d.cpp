#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    map<ll, int> indexMap;
    set<ll> numbers;
    for(int i = 0; i < n; ++i)
    {
        if(indexMap[a[i]])
        {
            while(indexMap[a[i]])
            {
                indexMap[a[i]] = 0;
                numbers.erase(a[i]);
                a[i] *= 2;
                numbers.insert(a[i]);
            }
            indexMap[a[i]] = i + 1;
        }
        else
        {
            indexMap[a[i]] = i + 1;
            numbers.insert(a[i]);
        }
    }
    cout << numbers.size() << endl;
    vector<ll> res(n, 0);
    for(auto it = numbers.begin(); it != numbers.end(); ++it)
        res[indexMap[*it] - 1] = *it;
    for(int i = 0; i < n; ++i)
        if(res[i])
            cout << res[i] << " ";
    cout << endl;
}