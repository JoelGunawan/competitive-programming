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
const ll limit = 100000;
struct sparse_table {
    ll a[18][limit];
    void build(vector<ll> arr) {
        for(ll i = 0; i < 18; ++i)
            for(ll j = 0; j < limit; ++j)
                a[i][j] = LLONG_MAX;
        for(ll i = 0; i < arr.size(); ++i) { 
            a[0][i] = arr[i];
        }
        for(ll i = 1; i < 18; ++i) {
            for(ll j = 0; j + (1 << i) <= limit; ++j) {
                a[i][j] = min(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    ll query(ll l, ll r) {
        if(l > r)
            return LLONG_MAX;
        ll dist = r - l + 1, res = LLONG_MAX;
        for(ll i = 17; i >= 0; --i) {
            if(dist >= 1 << i) {
                res = min(res, a[i][l]);
                l += 1 << i;
                dist -= 1 << i;
            }
        }
        return res;
    }
};
// NOTE FOR DEBUGGING DO ALL POSSIBLE LINES
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);
    ll n, m;
    cin >> n >> m;
    if((n & 1) && (m & 1))
        std::cout << -1 << endl, exit(0);
    // n <= 2 method: 
    // just brute force every starting position
    // and every possible tour
    vector<pair<ll, ll>> operations;
    // a[i][j] > 0 just create a random tour
    operations.pb(mp(1, 1));
    if(n & 1) {
        for(ll i = 1; i <= m; ++i) {
            if(i & 1)
                for(ll j = 2; j <= n; ++j)
                    operations.pb(mp(j, i));
            else
                for(ll j = n; j >= 2; --j)
                    operations.pb(mp(j, i));
        }
        for(ll i = m; i > 1; --i)
            operations.pb(mp(1, i));
    }
    else {
        for(ll i = 1; i <= n; ++i) {            
            if(i & 1)
                for(ll j = 2; j <= m; ++j)
                    operations.pb(mp(i, j));
            else
                for(ll j = m; j >= 2; --j)
                    operations.pb(mp(i, j));
        }
        for(ll i = n; i > 1; --i)
            operations.pb(mp(i, 1));
    }
    // only one a[i][j] < 0, choose that index last
    ll a[n][m];
    for(ll i = 0; i < n; ++i)
        for(ll j = 0; j < m; ++j)
            cin >> a[i][j];
    ll sum = 0;
    for(ll i = 0; i < n; ++i)
        for(ll j = 0; j < m; ++j)
            sum += a[i][j];
    if(sum < 0)
        std::cout << -1 << endl, exit(0);
    ll op_number[n][m];
    for(ll i = 0; i < operations.size(); ++i) {
        op_number[operations[i].fi - 1][operations[i].se - 1] = i;
    }
    //for(ll i = 0; i < n; ++i)
    //    for(ll j = 0; j < m; ++j)
    //        std::cout << op_number[i][j] << " ";
    vector<ll> prefix = {0}, suffix = {0};
    for(ll count = 0; count < 2; ++count) {
        for(auto i : operations) 
            prefix.pb(prefix.back() + a[i.fi - 1][i.se - 1]);
    }
    prefix.erase(prefix.begin());
    std::reverse(operations.begin(), operations.end());
    for(ll count = 0; count < 2; ++count) {
        for(ll j = 0; j < operations.size(); ++j) {
            pair<ll, ll> i = operations[j];
            suffix.pb(suffix.back() + a[i.fi - 1][i.se - 1]);
        }
    }
    suffix.erase(suffix.begin());
    std::reverse(suffix.begin(), suffix.end());
    sparse_table pref, suff;
    pref.build(prefix), suff.build(suffix);
    std::reverse(operations.begin(), operations.end());
    // brute force each index
    // total complexity -> O(nmlognm)
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            if(a[i][j] < 0)
                continue;
            // we can do the operations forwards or backwards
            ll idx = op_number[i][j];
            bool ans = 1;
            //cout << pref.query(idx, idx + (n * m)) << " " << prefix[(idx - 1 + operations.size()) % operations.size()] << endl;
            //cout << suff.query(idx, idx + (n * m)) << " " << suffix[(idx + 1) % operations.size()] << endl;
            int tmp = idx + (n * m) + 1;
            if(tmp > suffix.size())
                tmp = 0;
            else
                tmp = suffix[tmp];
            int tmp2 = idx - 1 + operations.size();
            if(tmp2 >= operations.size())
                tmp2 = 0;
            else
                tmp2 = prefix[tmp2];
            if(pref.query(idx, idx + (n * m)) >= prefix[(idx - 1 + operations.size()) % operations.size()]) {
                ll tmp = idx;
                do {
                    std::cout << operations[idx].fi << " " << operations[idx].se << endl;
                    ++idx;
                    idx %= operations.size();
                } while(idx != tmp);
                return 0;
            }
            else if(suff.query(idx, idx + (n * m)) >= tmp) {
                ll tmp = idx;
                do {
                    std::cout << operations[idx].fi << " " << operations[idx].se << endl;
                    --idx;
                    idx += operations.size();
                    idx %= operations.size();
                } while(idx != tmp);
                return 0;
            }
        }
    }
    for(int i = 0; i < operations.size(); ++i) {
        operations[i].fi = n - operations[i].fi + 1, operations[i].se = m - operations[i].se + 1;
    }
    for(ll i = 0; i < operations.size(); ++i) {
        op_number[operations[i].fi - 1][operations[i].se - 1] = i;
    }
    //for(ll i = 0; i < n; ++i)
    //    for(ll j = 0; j < m; ++j)
    //        std::cout << op_number[i][j] << " ";
    prefix = {0}, suffix = {0};
    for(ll count = 0; count < 2; ++count) {
        for(auto i : operations) 
            prefix.pb(prefix.back() + a[i.fi - 1][i.se - 1]);
    }
    prefix.erase(prefix.begin());
    std::reverse(operations.begin(), operations.end());
    for(ll count = 0; count < 2; ++count) {
        for(ll j = 0; j < operations.size(); ++j) {
            pair<ll, ll> i = operations[j];
            suffix.pb(suffix.back() + a[i.fi - 1][i.se - 1]);
        }
    }
    suffix.erase(suffix.begin());
    std::reverse(suffix.begin(), suffix.end());
    pref.build(prefix), suff.build(suffix);
    std::reverse(operations.begin(), operations.end());
    // brute force each index
    // total complexity -> O(nmlognm)
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            if(a[i][j] < 0)
                continue;
            // we can do the operations forwards or backwards
            ll idx = op_number[i][j];
            bool ans = 1;
            //cout << pref.query(idx, idx + (n * m)) << " " << prefix[(idx - 1 + operations.size()) % operations.size()] << endl;
            //cout << suff.query(idx, idx + (n * m)) << " " << suffix[(idx + 1) % operations.size()] << endl;
            int tmp = idx + (n * m) + 1;
            if(tmp > suffix.size())
                tmp = 0;
            else
                tmp = suffix[tmp];
            int tmp2 = idx - 1 + operations.size();
            if(tmp2 >= operations.size())
                tmp2 = 0;
            else
                tmp2 = prefix[tmp2];
            if(pref.query(idx, idx + (n * m)) >= prefix[(idx - 1 + operations.size()) % operations.size()]) {
                ll tmp = idx;
                do {
                    std::cout << operations[idx].fi << " " << operations[idx].se << endl;
                    ++idx;
                    idx %= operations.size();
                } while(idx != tmp);
                return 0;
            }
            else if(suff.query(idx, idx + (n * m)) >= tmp) {
                ll tmp = idx;
                do {
                    std::cout << operations[idx].fi << " " << operations[idx].se << endl;
                    --idx;
                    idx += operations.size();
                    idx %= operations.size();
                } while(idx != tmp);
                return 0;
            }
        }
    }
    if(n % 2 == 0 && m % 2 == 0) {
        operations.clear();
        for(ll i = 1; i <= m; ++i) {
            if(i & 1)
                for(ll j = 2; j <= n; ++j)
                    operations.pb(mp(j, i));
            else
                for(ll j = n; j >= 2; --j)
                    operations.pb(mp(j, i));
        }
        for(ll i = m; i > 1; --i)
            operations.pb(mp(1, i));
        ll op_number[n][m];
        for(ll i = 0; i < operations.size(); ++i) {
            op_number[operations[i].fi - 1][operations[i].se - 1] = i;
        }
        //for(ll i = 0; i < n; ++i)
        //    for(ll j = 0; j < m; ++j)
        //        std::cout << op_number[i][j] << " ";
        prefix = {0}, suffix = {0};
        for(ll count = 0; count < 2; ++count) {
            for(auto i : operations) 
                prefix.pb(prefix.back() + a[i.fi - 1][i.se - 1]);
        }
        prefix.erase(prefix.begin());
        std::reverse(operations.begin(), operations.end());
        for(ll count = 0; count < 2; ++count) {
            for(ll j = 0; j < operations.size(); ++j) {
                pair<ll, ll> i = operations[j];
                suffix.pb(suffix.back() + a[i.fi - 1][i.se - 1]);
            }
        }
        suffix.erase(suffix.begin());
        std::reverse(suffix.begin(), suffix.end());
        pref.build(prefix), suff.build(suffix);
        std::reverse(operations.begin(), operations.end());
        // brute force each index
        // total complexity -> O(nmlognm)
        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < m; ++j) {
                if(a[i][j] < 0)
                    continue;
                // we can do the operations forwards or backwards
                ll idx = op_number[i][j];
                bool ans = 1;
                //cout << pref.query(idx, idx + (n * m)) << " " << prefix[(idx - 1 + operations.size()) % operations.size()] << endl;
                //cout << suff.query(idx, idx + (n * m)) << " " << suffix[(idx + 1) % operations.size()] << endl;
                int tmp = idx + (n * m) + 1;
                if(tmp > suffix.size())
                    tmp = 0;
                else
                    tmp = suffix[tmp];
                int tmp2 = idx - 1 + operations.size();
                if(tmp2 >= operations.size())
                    tmp2 = 0;
                else
                    tmp2 = prefix[tmp2];
                if(pref.query(idx, idx + (n * m)) >= prefix[(idx - 1 + operations.size()) % operations.size()]) {
                    ll tmp = idx;
                    do {
                        std::cout << operations[idx].fi << " " << operations[idx].se << endl;
                        ++idx;
                        idx %= operations.size();
                    } while(idx != tmp);
                    return 0;
                }
                else if(suff.query(idx, idx + (n * m)) >= tmp) {
                    ll tmp = idx;
                    do {
                        std::cout << operations[idx].fi << " " << operations[idx].se << endl;
                        --idx;
                        idx += operations.size();
                        idx %= operations.size();
                    } while(idx != tmp);
                    return 0;
                }
            }
        }
        for(int i = 0; i < operations.size(); ++i) {
            operations[i].fi = n - operations[i].fi + 1, operations[i].se = m - operations[i].se + 1;
        }
        for(ll i = 0; i < operations.size(); ++i) {
            op_number[operations[i].fi - 1][operations[i].se - 1] = i;
        }
        //for(ll i = 0; i < n; ++i)
        //    for(ll j = 0; j < m; ++j)
        //        std::cout << op_number[i][j] << " ";
        prefix = {0}, suffix = {0};
        for(ll count = 0; count < 2; ++count) {
            for(auto i : operations) 
                prefix.pb(prefix.back() + a[i.fi - 1][i.se - 1]);
        }
        prefix.erase(prefix.begin());
        std::reverse(operations.begin(), operations.end());
        for(ll count = 0; count < 2; ++count) {
            for(ll j = 0; j < operations.size(); ++j) {
                pair<ll, ll> i = operations[j];
                suffix.pb(suffix.back() + a[i.fi - 1][i.se - 1]);
            }
        }
        suffix.erase(suffix.begin());
        std::reverse(suffix.begin(), suffix.end());
        pref.build(prefix), suff.build(suffix);
        std::reverse(operations.begin(), operations.end());
        // brute force each index
        // total complexity -> O(nmlognm)
        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < m; ++j) {
                if(a[i][j] < 0)
                    continue;
                // we can do the operations forwards or backwards
                ll idx = op_number[i][j];
                bool ans = 1;
                //cout << pref.query(idx, idx + (n * m)) << " " << prefix[(idx - 1 + operations.size()) % operations.size()] << endl;
                //cout << suff.query(idx, idx + (n * m)) << " " << suffix[(idx + 1) % operations.size()] << endl;
                int tmp = idx + (n * m) + 1;
                if(tmp > suffix.size())
                    tmp = 0;
                else
                    tmp = suffix[tmp];
                int tmp2 = idx - 1 + operations.size();
                if(tmp2 >= operations.size())
                    tmp2 = 0;
                else
                    tmp2 = prefix[tmp2];
                if(pref.query(idx, idx + (n * m)) >= prefix[(idx - 1 + operations.size()) % operations.size()]) {
                    ll tmp = idx;
                    do {
                        std::cout << operations[idx].fi << " " << operations[idx].se << endl;
                        ++idx;
                        idx %= operations.size();
                    } while(idx != tmp);
                    return 0;
                }
                else if(suff.query(idx, idx + (n * m)) >= tmp) {
                    ll tmp = idx;
                    do {
                        std::cout << operations[idx].fi << " " << operations[idx].se << endl;
                        --idx;
                        idx += operations.size();
                        idx %= operations.size();
                    } while(idx != tmp);
                    return 0;
                }
            }
        }
    }
    std::cout << -1 << endl;
    /*ll idx = 0;
    ll x, y;
    for(ll i = 0; i < n; ++i)
        for(ll j = 0; j < m; ++j)
            if(a[i][j] < 0)
                x = i + 1, y = j + 1;
    for(ll i = 0; i < operations.size(); ++i)
        if(operations[i].fi == x && operations[i].se == y)
            idx = i;
    ll tmp = idx;
    ++idx;
    while(idx != tmp) {
        std::cout << operations[idx].fi << " " << operations[idx].se << endl;
        ++idx;
        idx %= operations.size();
    }
    std::cout << operations[idx].fi << " " << operations[idx].se << endl;
    */
    return 0;
}