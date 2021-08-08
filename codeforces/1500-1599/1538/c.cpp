#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void test_case()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    int left = 1, right = n - 1;
    long long res = 0;
    for(int i = 0; i < n - 1; ++i)
    {
        // check whether the left is big enough, while it isn't try to add it
        while(left < n && a[left] + a[i] < l)
            ++left;
        // try to minimize the left
        while(left > i + 1 && a[left - 1] + a[i] >= l)
            --left;
        // check whether right is small enough, while it isn't try to decrease it
        while(right > i && a[i] + a[right] > r)
            --right;
        // try to maximize right
        while(right < n - 1 && a[i] + a[right + 1] <= r)
            ++right;
        // if left or right is <= i than there is no answer
        // set left and right to max(i + 1, var)
        if(left > i && right > i && right >= left)
            res += right - left + 1;
        left = max(left, i + 2); right = max(right, i + 2);
    }
    cout << res << endl;
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