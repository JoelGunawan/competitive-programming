#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define lll __int128
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fi first
#define se second
#define ins insert
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
vector<vector<int>> nxt = {{1, -1, 0, 0}, {0, 0, 1, -1}};
struct BIT {
    int arr[50005], arr_size = 50005;
    BIT() {
        memset(arr, 0, sizeof(arr));
    }
    void upd(int l, int r, int val) {
        if(l > r)
            return;
        while(l < arr_size)
            arr[l] += val, l += (l&-l);
        ++r;
        while(r < arr_size)
            arr[r] -= val, r += (r&-r);
    }
    int q(int idx) {
        int res = 0;
        while(idx > 0)
            res += arr[idx], idx -= (idx&-idx);
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    char m[q], p[q];
    for(int i = 0; i < q; ++i)
        cin >> m[i];
    for(int i = 0; i < q; ++i)
        cin >> p[i];
    BIT bit;
    map<pair<int, int>, int> cell;
    int x = 0, y = 0, time = 0;
    for(int i = n - 1; i >= 0; --i) {
        cell[mp(i, 0)] = n - i - 1;
    }
    bit.upd(n, n, min(q, n - 2));
    for(int i = n - 1; i >= 3; --i)
        bit.upd(i, i, min(q, i - 2) * 2);
    bit.upd(2, min(q + 1, n - 1), 1);
    for(int i = 1; i <= q; ++i) {
        if(m[i - 1] == 'L')
            --x;
        else if(m[i - 1] == 'R')
            ++x;
        else if(m[i - 1] == 'D')
            --y;
        else    
            ++y;
        ++time;
        cell[mp(x, y)] = time + n - 1;
        for(int j = 0; j < nxt[0].size(); ++j) {
            int cur_x = x + nxt[0][j], cur_y = y + nxt[1][j];
            pair<int, int> cur = mp(cur_x, cur_y);
            if(cell[cur] >= time) {
                // start point itu time
                // cari jarak time ke cell[cur];
                bit.upd(1, min(1 + q - i, cell[cur] - time + 1), 1);
                bit.upd(n - (cell[cur] - time + 1) + 1, min(n - (cell[cur] - time + 1) + 1 + q - i, n), 1);
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        cout << bit.q(i + 1) << endl;
    }
    return 0;
}