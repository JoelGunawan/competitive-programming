#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; ++i)
    {
        int input;
        cin >> input;
        a[i] = make_pair(input, i + 1);
    }
    sort(a.begin(), a.end());
    cout << a[n - 2].second << endl;
}