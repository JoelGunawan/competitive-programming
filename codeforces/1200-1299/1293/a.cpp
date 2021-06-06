#include <bits/stdc++.h>

using namespace std;

void tc()
{
    int n, s, k;
    cin >> n >> s >> k;
    vector<int> a(k);
    for(int i = 0; i < k; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    int left = s, right = s;
    while((binary_search(a.begin(), a.end(), left) || left <= 0) && (binary_search(a.begin(), a.end(), right) || right >= n + 1))
    {
        --left;
        ++right;
    }
    cout << s - left << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}
