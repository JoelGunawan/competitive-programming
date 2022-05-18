#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#pragma GCC optimize("Ofast")
using namespace std;
struct segtree
{
    vector<int> a[16]; int arr_size = (1 << 15);
    segtree()
    {
        for(int i = 0; i < 16; ++i)
            a[i] = vector<int>(1 << 15, 0);
    }
    void update(int index, int value)
    {
        for(int i = 0; i < 16; ++i)
            a[i][index] = value;
    }
    void balance(int depth, int left, int right)
    {
        sort(a[depth].begin() + left, a[depth].begin() + right + 1);
        if(depth != 15)
        {
            ++depth;
            int mid = (left + right) / 2;
            balance(depth, left, mid), balance(depth, mid + 1, right);
        }
    }
    int query(int depth, int left, int right, int cur_left, int cur_right, int value)
    {
        //cout << depth << " " << cur_left << " " << cur_right << endl;
        if(cur_left > right || cur_right < left)
            return 0;
        else if(cur_left >= left && cur_right <= right)
            return a[depth].begin() + cur_right - --upper_bound(a[depth].begin() + cur_left, a[depth].begin() + cur_right + 1, value);
        else
        {
            int mid = (cur_left + cur_right) / 2;
            ++depth;
            return query(depth, left, right, cur_left, mid, value) + query(depth, left, right, mid + 1, cur_right, value);
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    segtree seg;
    unordered_map<int, int> mp;
    unordered_map<int, bool> vis;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int next[n];
    for(int i = 0; i < n; ++i)
        next[i] = 2e9;
    for(int i = n - 1; i >= 0; --i)
    {
        if(vis[a[i]])
            next[i] = mp[a[i]];
        vis[a[i]] = 1, mp[a[i]] = i;
        seg.update(i, next[i]);
    }
    //for(int i = 0; i < n; ++i)
    //    cout << next[i] << " ";
    //cout << endl;
    seg.balance(0, 0, seg.arr_size - 1);
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << seg.query(0, l, r, 0, seg.arr_size - 1, r) << endl;
    }
    return 0;
}