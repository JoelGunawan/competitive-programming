// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
/*
const int lim = 1 << 18;
struct segment_tree {
    // replace zero with LLONG_MIN for max query
    // replace zero with LLONG_MAX for min query
    long long a[2 * lim], arr_size = lim, zero = 1e9;
    segment_tree() {
        fill(a, a + 2 * lim, zero);
    }
    long long merge(long long a, long long b) {
        return min(a, b);
    }
    void update(int idx, long long val) {
        idx += arr_size;
        a[idx] = val;
        while(idx > 1) {
            idx >>= 1;
            a[idx] = merge(a[2 * idx], a[2 * idx + 1]);
        }
    }
    long long query(int nd, int cl, int cr, int l, int r) {
        if(cl >= l && cr <= r) {
            return a[nd];
        }
        else if(cl > r || cr < l)
            return zero;
        else {
            int mid = (cl + cr) / 2;
            return merge(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
    int query(int l, int r) {
        return query(1, 0, arr_size - 1, l, r);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // bsta + string hashing?
    // bsta answer, coba partisi dengan ambil kurang dari x or smthg? -> gaperlu
    // yang bermasalah -> sisa
    // sisa ditaruh mana? ada 2^n kemungkinan sisanya
    // yang penting hanya yang ukuran + sisa aja (kecuali semuanya perfect)
    // beda antar tempatnya harus kelipatan floor(n / k) dari nextnya
    // pakai dp[n], terus ambil dari tiap keliaptan sebelumnya, cek minimumnya berapa
    // state dp: l, r denoting the minimum value of the partition
    // observe: sqrt is max, since antara simpen memo in modulo form atau coba satu per satu (not neccessary i think, always simpan in modulo form aja terus dijalanin over entire arr)
    // buat string 3 kali lipat supaya tau kalo start di akhir hasilnya gmn
    // maximum partisi diambil k kali
    // tiap run O(N)
    // cek state dp gmn?
    // harus bisa cari yang maksnya minimal tapi jumlah partisinya k
    // O(NK) -> dp[n][k] = max(cost(n), min(dp[n - i][k - 1])));
    // i -> multiple of k (atau nanti bs di modif gampang lah)
    // alien trick sus
    // size of partition pasti kurang dari half
    // jadi coba lagi start yang di tengah dan coba recalculate, karena nanti hasilnya sama aja
    // atau kita coba tentuin mana yang max? terus nanti di binser dr situ?
    // coba dengan elemen kurang dari x, kita bisa construct atau ngga?
    // kalo bisa, berarti boleh coba elemen yang nilainya lebih rendah?
    // boleh ambil too much, ga boleh ambil too little
    // ambil too much -> ez compensate
    // panjang partisi: ceil(n / k)
    // jumlah partisi: howevermuch sisa :D
    // sorting
    // nanti buat bsta dp
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = s + s;
    s = " " + s;
    // how to bsta dp?
    // do bsta on max elem and determine positions we can use x + 1
    // each dp state memo minimum amount of elements to get to pos x
    int mx = n / k + (bool)(n % k);
    vector<pair<string, int>> arr;
    for(int i = mx; i <= 2 * n; ++i) {
        // ambil dari i - mx + 1 ke mx
        arr.push_back(mp(s.substr(i - mx + 1, mx), i));
    }
    sort(arr.begin(), arr.end());
    //for(auto i : arr)
    //    cout << i.fi << " " << i.se << endl;
    if(mx == 1) {
        cout << arr.back().fi << endl;
        return 0;
    }
    vector<int> sizes;
    for(int i = 0; i < arr.size(); ++i)
        sizes.pb(arr[i].se);
    // ini harus sorted, ending at int
    int l = 0, r = sizes.size() - 1, ans = sizes.size() - 1;
    while(l <= r) {
        int m = (l + r) / 2;
        bool allowed[2 * n + 1];
        memset(allowed, 0, sizeof(allowed));
        for(int i = 0; i <= m; ++i) {
            allowed[sizes[i]] = 1;
        }
        // do dp
        // do 2 * n?
        // terus nanti ambil pokoknya ukuran n aja :D
        // mx 1 -> ga bisa
        int dp[2 * n + 1];
        dp[0] = 0;
        //cout << m << endl;
        int cur = 1e9;
        //cout << m << endl;
        for(int i = 1; i <= n; ++i) { 
            fill(dp, dp + 2 * n + 1, 1e9);
            dp[i - 1] = 0;
            for(int j = i; j <= i + n - 1; ++j) {
                dp[j] = dp[max(i - 1, j - mx + 1)] + 1;
                if(allowed[j] && j >= mx) {
                    dp[j] = min(dp[j], dp[j - mx] + 1);
                }
                //cout << i - mx + 1 << " " << i - 1 << " " << dp[i] << endl;
            }       
            //cout << i << " " << dp[i + n - 1] << endl;
            cur = min(cur, dp[i + n - 1]);
        }
        if(cur <= k)
            r = m - 1, ans = m;
        else
            l = m + 1;
    }
    //cout << ans << endl;
    for(auto i : arr) {
        if(i.se == sizes[ans]) {
            cout << i.fi << endl;
            return 0;
        }
    }
    assert(false);
    return 0;
}
*/
int conv(char a) {
    return a - '0';
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    // basically terabas aja, ntar gapapa klo kita accidentally build more than neccessary
    // first iteration: 
    vector<int> cnt(max(10, n), 0), p(n), c(n);
    // p menandakan permutasi sorted
    // c menandakan class index i itu berapa
    for(int i = 0; i < n; ++i)
        ++cnt[conv(s[i])];
    for(int i = 1; i < max(10, n); ++i)
        cnt[i] += cnt[i - 1];// cout << cnt[i] << " ";
    //cout << endl;
    for(int i = n - 1; i >= 0; --i) {
        // nilai c itu didapet dr conv(s[i])
        // cout << p.size() << " " << cnt[conv(s[i])] << endl;
        //cout << s[i] << " " << cnt[conv(s[i])] << endl;
        p[--cnt[conv(s[i])]] = i;
        //cout << cnt[conv(s[i])] << " " << i << endl;
    }
    //for(int i = 0; i < n; ++i)
    //    cout << p[i] << " ";
    //cout << endl;
    c[0] = 0;
    int mxc = 1;
    for(int i = 1; i < n; ++i) {
        c[p[i]] = c[p[i - 1]];
        if(s[p[i]] != s[p[i - 1]])
            ++c[p[i]], ++mxc;
    }
    vector<int> pn(n), cn(n);
    for(int i = 0; (1 << i) < n; ++i) {
        // ambil new permutation itu pasti dari 1 - (1 << i)
        // karena kita mau jalan ke belakang !!!
        // berarti new permutation starts di belakang, use order of old permutation tapi kita append yang belakang gtu?
        for(int j = 0; j < n; ++j) {
            int tmp = p[j] - (1 << i);
            if(tmp < 0)
                tmp += n;
            pn[j] = tmp;
        }
        fill(cnt.begin(), cnt.begin() + n, 0);
        for(int j = 0; j < n; ++j)
            ++cnt[c[pn[j]]];
        for(int j = 1; j < n; ++j) 
            cnt[j] += cnt[j - 1];
        for(int j = n - 1; j >= 0; --j) {
            p[--cnt[c[pn[j]]]] = pn[j];
        }
        cn[p[0]] = 0;
        mxc = 1;
        for(int j = 1; j < n; ++j) {
            pair<int, int> cur = {c[p[j]], c[(p[j] + (1 << i)) % n]};
            pair<int, int> prev = {c[p[j - 1]], c[(p[j - 1] + (1 << i)) % n]};
            cn[p[j]] = cn[p[j - 1]];
            if(cur != prev)
                ++cn[p[j]], ++mxc; 
        }
        c.swap(cn);
    }
    int max_sz = (n + k - 1) / k;
    
}