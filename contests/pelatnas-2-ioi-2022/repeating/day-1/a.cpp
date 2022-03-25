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
int a[300005], b[300005];
struct bit {
    int a[600005];
    bit() {
        memset(a, 0, sizeof(a));
    }
    void upd(int idx, int val) {
        while(idx < 600005) {
            a[idx] += val;
            idx += (idx&-idx);
        }
    }
    int q(int l, int r) {
        return query(r) - query(l - 1); 
    }
    int query(int idx) {
        int res = 0;
        while(idx > 0) {
            res += a[idx];
            idx -= (idx&-idx);
        }   
        return res;
    }
};
int position[300005];
void dnc(int al, int ar, int bl, int br) {
    //cout << al << " " << ar << " " << bl << " " << br << endl;
    if(bl > br)
        return;
    if(al > ar)
        exit(0);
    int bmid = (bl + br) / 2, res = INT_MAX, res_idx = -1, suffix = 0, prefix = 0;
    // find optimal location for bmid
    // we just need to consider between al and ar
    // then we get the position in the array
    // put everything into the array but ar
    for(int i = al; i < ar; ++i) {
        if(a[i] < b[bmid])
            ++suffix;
    }
    //cout << al << " " << ar << endl;
    for(int i = al; i <= ar; ++i) {
        if(suffix + prefix <= res) {
            res_idx = i, res = suffix + prefix;
        }
        //cout << suffix << " " << prefix << " " << res << " " << res_idx << endl;
        if(i != ar) {
            if(a[i] < b[bmid])
                --suffix;
            if(a[i] > b[bmid])
                ++prefix;
        }
    }
    position[bmid] = res_idx;
    //cout << res_idx << endl;
    dnc(al, min(res_idx + 1, ar), bl, bmid - 1);
    dnc(res_idx, ar, bmid + 1, br);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // dp dnc
    set<int> all;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < m; ++i)
        cin >> b[i];
    sort(b, b + m);
    // dnc algo -> determine the position of b mid
    dnc(0, n, 0, m - 1);
    int idx = 0, cs = 0;
    int c[n + m];
    memset(c, -1, sizeof(c));
    for(int i = 0; i <= n; ++i) {
        while(idx < m && position[idx] == i) {
            c[cs++] = b[idx++];
        }
        if(i != n)
            c[cs++] = a[i];
    }
    //for(int i = 0; i < m; ++i)
    //    cout << position[i] << " ";
    //cout << endl;
    //for(auto i : c)
    //    cout << i << " ";
    //cout << endl;
    function<ll(int, int)> merge = [&] (int l, int r) -> ll {
        // cari jumlah elemen yang lebih kecil di kanan
        int mid = (l + r) / 2;
        if(l >= r)
            return 0;
        ll res = 0;
        res += merge(l, mid);
        res += merge(mid + 1, r);
        // do merge process
        int lidx = l, ridx = mid + 1;
        int tmp[r - l + 1];
        memset(tmp, -1, sizeof(tmp));
        int idx = 0;
        while(idx < r - l + 1) {
            if(lidx <= mid && (ridx > r || c[lidx] <= c[ridx])) {
                res += ridx - (mid + 1);
                //cout << lidx << " " << ridx << endl;
                //cout << c[lidx] << " " << c[ridx] << endl;
                tmp[idx++] = c[lidx++];
            }
            else
                tmp[idx++]= c[ridx++];
        }
        //cout << l << " " << r << " " << res << endl;
        for(int i = l; i <= r; ++i)
            c[i] = tmp[i - l];
        return res;
    };
    //cout << endl;
    cout << merge(0, n + m - 1) << endl;
    return 0;
}