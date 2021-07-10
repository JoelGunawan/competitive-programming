#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string subsoal; int n;
    cin >> subsoal >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> spans;
    int streak = 0;
    for(int i = 0; i < n; ++i)
    {
        if(i != 0 && a[i] != a[i - 1])
        {
            spans.push_back(streak);
            streak = 0;
        }
        ++streak;
    }
    spans.push_back(streak);
    ll res = 0;
    for(int i = 0; i < spans.size(); ++i)
        res += spans[i] * (ll)(spans[i] + 1) / 2;
    cout << res << endl;
    return 0;
}