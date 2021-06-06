#include <bits/stdc++.h>

using namespace std;

void tc()
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> a(n);
    for(int i = 0; i < n; ++i)
    {
        int t, l, h;
        cin >> t >> l >> h;
        a[i] = make_tuple(t, l, h);
    }
    sort(a.begin(), a.end());
    int time = 0, l = m, h = m;
    for(int i = 0; i < n; ++i)
    {
        l -= get<0>(a[i]) - time;
        h += get<0>(a[i]) - time;
        time = get<0>(a[i]);
        l = max(l, get<1>(a[i])); h = min(h, get<2>(a[i]));
        if(l > get<2>(a[i]) || h < get<1>(a[i]))
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main()
{
    int q;
    cin >> q;
    while(q--)
        tc();
    return 0;
}
