#include <bits/stdc++.h>

using namespace std;

void tc()
{
    int n;
    cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n; ++i)
        cin >> s[i];
    sort(s.begin(), s.end());
    int minimum = INT_MAX;
    for(int i = 1; i < n; ++i)
        minimum = min(s[i] - s[i - 1], minimum);
    cout << minimum << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}
