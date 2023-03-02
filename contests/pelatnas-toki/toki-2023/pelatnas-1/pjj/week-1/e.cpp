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

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
    // t == 20
    // each tc -> 500 ms
    // n = 9 maximum
    // 9! = ~4e5
    // transitions: take any subarray -> 45
    // calculations of cut operations -> 9
    // amortized probably much lower?
    // can dijkstra
    // choose subarray to be sorted/put into a certain area
    /*
    int n;
    int case_num = 0;
    while(cin >> n) {
        if(n == 0)
            return 0;
        case_num++;
        cout << "Case " << case_num << ": ";
        assert(n > 1 && n < 10);
        vector<int> a(n);
        for(int i = 1; i <= n; ++i) {
            cin >> a[i - 1];
        }
        // operasi: coba tiap subarray, pindah ke tempat lain
        map<vector<int>, bool> vis;
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
        pq.push(mp(0, a));
        vector<int> target;
        for(int i = 1; i <= n; ++i)
            target.pb(i);
        int ans = 0;
        while(pq.size()) {
            int dist = pq.top().fi; vector<int> cur = pq.top().se;
            if(cur == target) {
                ans = dist;
                break;
            }
            pq.pop();
            if(vis[cur])
                continue;
            vis[cur] = 1;
            // coba tiap transisi/subarray
            for(int i = 1; i <= n; ++i) {
                for(int j = i; j <= n; ++j) {
                    // cut/paste for i to j
                    int cut_ops = 0; vector<int> narr;
                    for(int k = 0; k < n; ++k) {
                        if(cur[k] < i || cur[k] > j)
                            narr.pb(cur[k]);
                        else {
                            if(k != 0) {
                                if(cur[k] != cur[k - 1] + 1 || cur[k] == i)
                                    ++cut_ops;
                            }
                            else
                                ++cut_ops;
                        }
                    }
                    // buat array baru, selipkan di terserah mana aja
                    for(int k = 0; k <= narr.size(); ++k) {
                        vector<int> fin;
                        for(int l = 0; l < k; ++l)
                            fin.pb(narr[l]);
                        for(int l = i; l <= j; ++l)
                            fin.pb(l);
                        for(int l = k; l < narr.size(); ++l)
                            fin.pb(narr[l]);
                        if(!vis[fin])
                            pq.push(mp(dist + cut_ops, fin));
                    }
                }
            }
        }
        cout << ans << endl;
    }
    */
    // buat bitmask untuk menyatakan sebuah subsequence tertentu itu yang terurut
    // sisanya harus diubah supaya sesuai urutannya
    int n;
    while(cin >> n) {
        if(n == 0)
            return;
        int a[n];
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for(int i = 0; i < (1 << n); ++i) {
            // contiguous -> lakukan bersamaan cut/pastenya
            vector<int> check_sorted;
            for(int j = 0; j < n; ++j) {
                if((1 << j) & i)
                    check_sorted.pb(a[j]);
            }
            vector<int> check_sorted2 = check_sorted;
            sort(check_sorted2.begin(), check_sorted2.end());
            if(check_sorted != check_sorted2)
                continue;
            // cut in order buat contiguous groupings
            // tapi antar group harus brute force tiap permutasi cut/paste
            
        }
    }
    vector<int> a = {3, 25, 25, 15, 16, 92};
    for(int i = 0; i < a.size(); i++)

    return 0;
}