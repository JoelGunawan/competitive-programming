#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ins insert
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    fast_io();
    int n, q;
    cin >> n >> q;
    map<string, string> m;
    string name, number;
    for(int i = 0; i < n; ++i)
        cin >> name >> number, m[name] = number;
    for(int i = 0; i < q; ++i)
    {
        cin >> name;
        if(m[name].size() == 0)
            cout << "NIHIL" << endl;
        else
            cout << m[name] << endl;
    }
    return 0;
}