#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize("Ofast")
using namespace std;
struct bit
{
    int a[5001];
    void clear()
    {
        memset(a, 0, sizeof(a));
    }
    int query(int index)
    {
        int res = 0;
        while(index >= 1)
        {
            res += a[index];
            index -= (index&-index);
        }
        return res;
    }
    void update(int index, int value)
    {
        while(index <= 5000)
        {
            a[index] += value;
            index += (index&-index);
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i], b[i] = a[i];
    bit bit;
    int minimum = INT_MAX, res = 0, total = 0;
    // O(n^2) to count total inversions
    for(int i = 1; i < n; ++i)
        for(int j = i; j > 0 && b[j] < b[j - 1]; --j)
            swap(b[j], b[j - 1]), ++total;
    // find how much we can minimize
    for(int i = 0; i < n; ++i)
    {
        bit.clear();
        for(int j = i + 1; j < n; ++j)
        {
            if(a[i] > a[j])
            {
                int x = bit.query(a[i] - 1), y = bit.query(a[j]);
                if(total - (2 * (x - y) + 1) < minimum)
                    minimum = total - (2 * (x - y) + 1), res = 1;
                else if(total - (2 * (x - y) + 1) == minimum)
                    ++res;    
            }
            bit.update(a[j], 1);
        }
    }
    cout << minimum << " " << res << endl;
    return 0;
}