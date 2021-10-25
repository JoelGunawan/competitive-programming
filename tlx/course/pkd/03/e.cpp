#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ins insert
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
using namespace std;
bool compare_string(string a, string b)
{
    if(a.size() != b.size())
        return a.size() < b.size();
    else
        return a < b;
}
int main()
{
    fast_io();
    int n;
    cin >> n;
    string a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n, compare_string);
    for(int i = 0; i < n; ++i)
        cout << a[i] << endl;
    return 0;
}