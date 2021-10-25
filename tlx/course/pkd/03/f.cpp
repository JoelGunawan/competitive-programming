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
    int n;
    cin >> n;
    set<string> a;
    string input;
    for(int i = 0; i < n; ++i)
    {
        cin >> input;
        a.insert(input);
        cout << distance(a.begin(), a.find(input)) + 1 << endl;
    }
    return 0;
}