#include <bits/stdc++.h>

using namespace std;

void tc()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> used(n + 1, -1);
    for(int i = 0; i < n; ++i)
    {
        if(used[a[i]] != -1 && i - used[a[i]] > 1)
        {
            cout << "YES" << endl;
            return;
        }
        else if(used[a[i]] == -1)
            used[a[i]] = i;
    }
    cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}
