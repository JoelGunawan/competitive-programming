#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
void test_case()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; ++i)
        cin >> h[i];
    sort(h.begin(), h.end());
    int chosen, minDiff = INT_MAX;
    for(int i = 0; i < n - 1; ++i)
    {
        if(h[i + 1] - h[i] < minDiff)
        {
            minDiff = h[i + 1] - h[i];
            chosen = i;
        }
    }
    vector<int> res(n);
    res[0] = h[chosen]; res[n - 1] = h[chosen + 1];
    int index = (chosen + 2) % n, i = 1;
    while(index != chosen)
    {
        res[i] = h[index];
        ++index; ++i;
        index %= n;
    }
    for(int i = 0; i < n; ++i)
        cout << res[i] << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}