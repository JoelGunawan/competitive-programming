// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
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
int n;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
    if(a == -1 || b == -1) 
        return -1;
    ll ret = 1ll * a / gcd(a, b) * b;
    if(ret > 2 * n)
        return -1;
    else
        return ret;
}
struct sparse_table {
    vector<int> a[19];
    int sz;
    vector<int> log2;
    sparse_table(int size) {
        for(int i = 0; i < 19; ++i)
            a[i].resize(size);
        log2.resize(size);
        sz = size;
        log2[0] = log2[1] = 0;
        for(int i = 2; i < size; ++i) {
            log2[i] = log2[i >> 1] + 1;
        }
    }
    void build() {
        for (int i = 1; i < 19; i++)
            for (int j = 1; j + (1 << i) <= sz; j++)
                a[i][j] = lcm(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
    }
    int query(int l, int r) {
        int i = log2[r - l + 1];
        return lcm(a[i][l], a[i][r - (1 << i) + 1]);
    }
};
void tc() {
    cin >> n;
    int a[n + 1];
    sparse_table sp(n + 1);
    // find unique lcms dari sebuah index sampe 1e9 klo mau aman
    // nanti tiap index cri unique lcm, ada at most log indices
    // NlogNlog1e9
    // logN -> segtree
    // log1e9 -> lcm
    bool vis[2 * n + 1];
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    // segtree -> O(NlogNlogAi)
    // sparse table binser -> O(NlogNlogAi) (but faster)
    // total numbers: O(NlogAi) (but amortized 2N or something, jadi harus hapus duplikat cepet)
    for(int i = 1; i <= n; ++i) {
        int curl = i; ll curlcm = a[i];
        if(curlcm > 2 * n)
            continue;
        vis[curlcm] = 1;
        //cout << i << " " << curlcm << endl;
        int q = -1, l, r;
        l = i + 1, r = n;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(lcm(sp.query(i, mid), curlcm) != curlcm)
                q = mid, r = mid - 1;
            else
                l = mid + 1; 
        }
        while(q != -1 && q <= n) {
            //cout << "DEBUG " << i << " " << q << endl;
            curlcm = lcm(curlcm, a[q]);
            if(curlcm == -1 || curlcm > 2 * n)
                break;
            vis[curlcm] = 1;
            // karena nanti di i + 1 juga dikunjungi kan?
            //cout << i << " " << curlcm << endl;
            curl = q;
            q = -1;
            l = curl + 1, r = n;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(lcm(sp.query(i, mid), curlcm) != curlcm)
                    q = mid, r = mid - 1;
                else
                    l = mid + 1;
            }
        }
    }
    for(int i = 1; i <= 2 * n; ++i) {
        if(!vis[i]) {
            cout << i << endl;
            return;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
    return 0;
}