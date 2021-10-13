#include <bits/stdc++.h>
using namespace std;
int main()
{
    // input
    string subsoal; int n, s;
    cin >> subsoal >> n >> s;
    int a[n + 1], p, q; a[0] = 0;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> p;
    int x[p];
    for(int i = 0; i < p; ++i)
        cin >> x[i];
    cin >> q;
    int y[q];
    for(int i = 0; i < q; ++i)
        cin >> y[i];
    set<int> common, our;
    sort(x, x + p), sort(y, y + q);
    // fill values of common and our
    for(int i = 0; i < p; ++i)
    {
        if(binary_search(y, y + q, x[i]))
            common.insert(x[i]);
        else
            our.insert(x[i]);
    }
    bool ourmove = 1, dengklekmove = 1;
    while(ourmove || dengklekmove)
    {
        while(common.size() > 0)
        {
            if(a[*common.begin()] == 0)
                common.erase(common.begin());
            else
                break;
        }
        while(our.size() > 0)
        {
            if(a[*our.begin()] == 0)
                our.erase(our.begin());
            else
                break;
        }
        if(common.size() > 0)
            cout << *common.begin() << endl, --a[*common.begin()];
        else if(our.size() > 0)
            cout << *our.begin() << endl, --a[*our.begin()];
        else
            cout << 0 << endl, ourmove = 0;
        if(!ourmove && !dengklekmove)
            break;
        int query;
        cin >> query;
        dengklekmove = query;
        --a[query];
    }
    return 0;
}