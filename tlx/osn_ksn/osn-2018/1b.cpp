#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string subsoal; ll a, b, q;
    cin >> subsoal >> a >> b >> q;
    /*
    if(q == 0)
    {
        // use a modified euclid
        while(a > 0)
        {
            if(a > b)
                a %= (b + 1);
            else
                b %= a;
        }
        if(a == 0 && b == 0)
            cout << "MUNGKIN" << endl;
        else
            cout << "TIDAK MUNGKIN" << endl;
        return 0;
    }
    */
    vector<pair<ll, int>> index;
    ll cur = 0;
    while(a > 0)
    {
        if(a > b)
            index.push_back({cur + a / (b + 1) - 1, 1}), cur += a / (b + 1), a %= (b + 1);
        else
            index.push_back({cur + b / a - 1, 0}), cur += b / a, b %= a;
    }
    sort(index.begin(), index.end());
    if(a == 0 && b == 0)
        cout << "MUNGKIN" << endl;
    else
    {
        cout << "TIDAK MUNGKIN" << endl;
        return 0;
    }
    for(int i = 0; i < q; ++i)
    {
        ll l, r;
        cin >> l >> r;
        if(r >= cur)
        {
            cout << "DI LUAR BATAS" << endl;
            continue;
        }
        l = cur - l - 1, r = cur - r - 1;
        swap(l, r);
        //cout << l << " " << r << endl;
        for(ll j = r; j >= l; --j)
        {
            // find whether it is 0 or 1
            cout << (*lower_bound(index.begin(), index.end(), make_pair(j, 0))).second;
        }
        cout << endl;
    }
    /*
    string s;
    while(a > 0)
    {
        if(a > b)
            a = a - b - 1, s += '1';
        else
            b = b - a, s += '0';
    }
    if(a == 0 && b > 0)
    {
        cout << "TIDAK MUNGKIN" << endl;
        return 0;
    }
    else
        cout << "MUNGKIN" << endl;
    reverse(s.begin(), s.end());
    for(int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        if(r >= s.size())
            cout << "DI LUAR BATAS" << endl;
        else
        {
            for(int j = l; j <= r; ++j)
                cout << s[j];
            cout << endl;
        }
    }
    */
    return 0;
}