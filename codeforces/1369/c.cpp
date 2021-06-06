#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    deque<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    deque<int> w(k);
    for(int i = 0; i < k; i++)
        cin >> w[i];
    sort(a.begin(), a.end(), greater<int>());
    sort(w.begin(), w.end());
    long long result = 0;
    while(w.size() > 0 && w.front() == 1)
    {
        result += 2 * a.front();
        a.pop_front();
        w.pop_front();
    }
    reverse(w.begin(), w.end());
    while(w.size() > 0)
    {
        result += a.front() + a.back();
        a.pop_front();
        for(int i = 1; i < w.front(); i++)
            a.pop_back();
        w.pop_front();
    }
    cout << result << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
