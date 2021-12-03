#include <bits/stdc++.h>
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pf push_front
#define ll long long
#pragma GCC optimize("Ofast")
using namespace std;
struct segtree
{
    vector<ll> arr; int arr_size;
    void build(int size)
    {
        int tmp = 1;
        while(tmp < size)
            tmp *= 2;
        arr_size = tmp;
        arr = vector<ll>(tmp * 2, LLONG_MAX);
    }
    void update(int index, int value)
    {
        arr[index + arr_size] = value;
        private_update((index + arr_size) / 2);
    }
    ll merge(ll a, ll b)
    {
        return min(a, b);
    }
    void private_update(int index)
    {
        arr[index] = merge(arr[2 * index], arr[2 * index + 1]);
        if(index != 1)
            private_update(index / 2);
    }
    ll query(int cur, int cur_left, int cur_right, int left, int right)
    {
        if(cur_right < left || cur_left > right)
            return LLONG_MAX;
        else if(cur_left >= left && cur_right <= right)
            return arr[cur];
        else
        {
            int mid = (cur_left + cur_right) / 2;
            return merge(query(2 * cur, cur_left, mid, left, right), query(2 * cur + 1, mid + 1, cur_right, left, right));
        }
    }
};
void test_case()
{
    segtree seg;
    int n, s;
    cin >> n >> s;
    seg.build(n);
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    // segtree on prefix array
    // binary search minimum query for prefix array
    ll prefix[n];
    prefix[0] = a[0];
    for(int i = 1; i < n; ++i)
        prefix[i] = prefix[i - 1] + a[i];
    for(int i = 0; i < n; ++i)
        seg.update(i, prefix[i]);
    int max_len = 0, ans_left, ans_right;
    for(int i = 0; i < n; ++i)
    {
        if(s + a[i] >= 0)
        {
            int left = i, right = n - 1, res = left;
            while(left <= right)
            {
                int mid = (left + right) / 2;
                if((i == 0 && seg.query(1, 0, seg.arr_size - 1, i, mid) + s >= 0) || (i != 0 && seg.query(1, 0, seg.arr_size - 1, i, mid) - prefix[i - 1] + s >= 0))
                    res = mid, left = mid + 1;
                else
                    right = mid - 1;
            }
            if(res - i + 1 > max_len)
                ans_left = i + 1, ans_right = res + 1, max_len = res - i + 1;
        }
    }
    if(max_len == 0)
        cout << -1 << endl;
    else
        cout << ans_left << " " << ans_right << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}