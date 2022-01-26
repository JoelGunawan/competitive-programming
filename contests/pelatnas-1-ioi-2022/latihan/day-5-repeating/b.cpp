#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ll long long
#define fi first
#define se second
#pragma GCC optimize("Ofast")
using namespace std;
/*
vector<int> primes = generate_primes();
vector<int> generate_primes()
{
    int limit = 1e6;
    bool a[limit + 1]; memset(a, 1, sizeof(a));
    a[0] = 0, a[1] = 1;
    for(int i = 2; i <= limit / 2; ++i)
    {
        if(a[i])
            for(int j = 2 * i; j <= limit; ++j)
                a[j] = 0;
    }
    vector<int> res;
    for(int i = 0; i <= limit; ++i)
        if(a[i])
            res.pb(i);  
    return res;
}
*/
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
struct sparse_table
{
    ll a[18][(int)1e5 + 1];
    int memo[(int)1e5 + 1];
    sparse_table()
    {
        memset(a, 0, sizeof(a));
        memo[1] = 0;
        for(int i = 2; i < 1e5 + 1; ++i)
            memo[i] = memo[i >> 1] + 1;
    }
    void build(vector<ll> arr)
    {
        for(int i = 0; i < arr.size(); ++i)
            a[0][i] = arr[i];
        for(int i = 1; i < 17; ++i)
        {
            for(int j = 0; j + (1 << i) - 1 < arr.size(); ++j)
                a[i][j] = gcd(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
        }
    }
    ll query(int left, int right)
    {
        int dist = right - left + 1;
        int tmp = memo[dist];
        return gcd(a[tmp][left], a[tmp][right - (1 << tmp) + 1]);
    }
};
sparse_table sp;
void test_case()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    ll total_gcd = a[0];
    for(int i = 0; i < n; ++i)
        total_gcd = gcd(total_gcd, a[i]);
    for(int i = 0; i < n; ++i)
        a[i] /= total_gcd;
    sp.build(a);
    ll res = n;
    // binser gcd
    // pake prefix gcd
    // pake sparse table?
    for(int i = 0; i < n; ++i)
    {
        res = max(res, a[i]);
        ll cur_gcd = a[i];
        int last_idx = i;
        while(last_idx + 1 < n)
        {
            int left = last_idx + 1, right = n - 1, x = last_idx + 1;
            cur_gcd = gcd(cur_gcd, a[left]);
            if(cur_gcd == 1)
                break;
            while(left <= right)
            {
                int mid = (left + right) / 2;
                if(sp.query(i, mid) == cur_gcd)
                    left = mid + 1, x = mid;
                else
                    right = mid - 1;
            }
            res = max(res, (x - i + 1) * 1ll * cur_gcd);
            last_idx = x;
        }
    }
    // res must be multplied by total gcd
    cout << res * total_gcd << endl;
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