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
        arr = vector<ll>(tmp * 2, 0);
    }
    void update(int index, int value)
    {
        arr[index + arr_size] += value;
        //cout << "UPD: " << index << " " << arr[index + arr_size] << endl;
        private_update((index + arr_size) / 2);
    }
    ll merge(ll a, ll b)
    {
        return a + b;
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
            return 0;
        else if(cur_left >= left && cur_right <= right)
            return arr[cur];
        else
        {
            int mid = (cur_left + cur_right) / 2;
            return merge(query(2 * cur, cur_left, mid, left, right), query(2 * cur + 1, mid + 1, cur_right, left, right));
        }
    }
    ll q(int x) {
        return query(1, 0, arr_size - 1, 0, x);
    }
};
void test_case()
{
    segtree seg;
    int n, s;
    cin >> n >> s;
    ll a[n + 1];
    seg.build(n + 5);
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int r = 1, res = 0;
    int lr, rr;
    for(int i = 1; i <= n; ++i) {
        ll cur = a[i] + s;
        //cout << i << " " << cur << " " << seg.q(i) << endl;
        if(cur >= seg.q(i) && cur >= 0) {
            if(i > r)
                r = i;
            ll tmp = cur - seg.q(i);
            seg.update(i, tmp);
            seg.update(r + 1, -tmp);
            cur = seg.q(r);
            //cout << cur << " " << a[r + 1] << endl;
            while(r < n && cur + a[r + 1] >= 0) {
                ++r;
                cur += a[r];
                ll tmp = cur - seg.q(r);
                seg.update(r, tmp);
                seg.update(r + 1, -tmp);
                //cout << i << " " << cur << " " << r << " " << seg.q(r) << endl;
                //cout << "R: " << r << " " << cur << endl;
            }
            //cout << i << " " << r << endl;
            if(r - i + 1 >= res) {
                lr = i, rr = r;
                res = r - i + 1;
            }
        }
    }
    //cout << endl;
    //for(int i = 1; i <= n + 1; ++i)
    //    cout << seg.q(i) << " ";
    //cout << endl;
    //for(int i = 1; i < seg.arr.size(); ++i) 
        //cout << seg.arr[i] << " ";
    //cout << endl;
    if(res == 0)
        cout << -1 << endl;
    else
        cout << lr << " " << rr << endl;
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