// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
const int lim = 262144;
struct segtree {
    int a[2 * lim + 1], arr_size = lim;
    segtree() {
        for(int i = 0; i < 2 * lim + 1; ++i)
            a[i] = INT_MAX;
    }
    void update(int index, int value) {
        index = index + arr_size;
        a[index] = value;
        while(index > 1) {
            index >>= 1;
            a[index] = min(a[2 * index], a[2 * index + 1]);
        }
    }
    int query(int left, int right) {
        left += arr_size, right += arr_size;
        if(left == right)
            return a[left];
        int res = INT_MAX, tmp = arr_size;
        while(left < right) {
            res = min(res, a[left]);
            res = min(res, a[right]);
            if(left & 1)
                ++left;
            if(right % 2 == 0)
                --right;
            //cout << left - arr_size << " " << right - arr_size << endl;
            res = min(res, a[left]);
            res = min(res, a[right]);
            left /= 2, right /= 2;
        }
        return min(res, min(a[left], a[right]));
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    segtree seg;
    int n, q, in;
    cin >> n >> q;
    for(int i = 0; i < n; ++i)
        cin >> in, seg.update(i, in);
    for(int i = 0; i < q; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1)
            seg.update(a - 1, b);
        else
            cout << seg.query(a - 1, b - 1) << endl;
    }
    return 0;
}