#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // bukannya soal KSNP ya :thinkies:
    int n, cur;
    cin >> n;
    multiset<int> a;
    for(int i = 0; i < n; ++i)
    {
        cin >> cur;
        if(a.lower_bound(cur) != a.end())
        {
            a.erase(a.lower_bound(cur));
            a.insert(cur);
        }
        else
            a.insert(cur);
    }
    cout << a.size() << endl;
    return 0;
}