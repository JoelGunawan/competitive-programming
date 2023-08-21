// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    char a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    // sub 1
    /*
    cout << "YES" << endl;
    for(int i = 1; i <= n; ++i)
        cout << 0 << " ";
    cout << endl;
    */
    // sub 2
    // kalo JLO agk ribet
    // observasi intinya dia harus "bantu" yg terakhir supaya bs memenuhi
    // coba bagi jadi 2 bagian, start dan finish
    // yg start harus cocokin supaya bs diselesaiin yg finish
    // obs: jumlah J dan L harus genap
    // tiap J dipasangkan sama dirinya sendiri
    /*
    int jcnt = 0, lcnt = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] == 'J')
            ++jcnt;
        else if(a[i] == 'L')
            ++lcnt;
    }
    vector<int> p;
    int ans[n + 1];
    if((jcnt + lcnt) & 1) {
        cout << "NO" << endl;
        return 0;
    }
    int pr = -1;
    for(int i = 1; i <= n; ++i) {
        if(a[i] == 'O')
            ans[i] = 0;
        else if(pr == -1) {
            if(a[i] == 'J')
                pr = i;
            else
                pr = i;
        }
        else {
            if(a[i] == 'J') {
                ans[pr] = 3;
                ans[i] = 1;
                pr = -1;
            }
            else {
                ans[i] = 3;
                ans[pr] = 1;
                pr = -1;
            }
        }
    }
    cout << "YES" << endl;
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << endl;
    */
    // n <= 18 -> brute force aja
    // nanti simpan state itu left right yg ke sangkut ada berapa
    // nanti ada 2 kemungkinan, simpan tiap kemungkinan aja
    // bisa pakai rekursi aja biar gampang
    bool x = 0;
    for(int i = 0; i < (1 << n); ++i) {
        bool opt[n + 1];
        for(int j = 0; j < n; ++j) {
            if((1 << j) & i)
                opt[j + 1] = 1;
            else
                opt[j + 1] = 0;
        }
        // opt -> option
        vector<pair<int, int>> st;
        for(int j = 1; j <= n; ++j) {
            // J, L, O should be correct
            if(a[j] == 'O') {
                continue;
            }
            else if(a[j] == 'J') {
                // +2 di kiri bs hapus atau +2 di kanan gbs hapus
                if(opt[j]) {
                    // +2 di kiri bs hapus
                    if(st.size() && st.back().se == 0)
                        st.back().fi += 2;
                    else if(st.size() && st.back().se == 1) {
                        if(st.back().fi > 2)
                            st.back().fi -= 2;
                        else if(st.back().fi == 2)
                            st.pop_back();
                        else {
                            st.pop_back();
                            if(st.size() && st.back().se == 0)
                                ++st.back().fi;
                            else
                                st.pb(mp(1, 0));
                        }
                    }
                    else
                        st.pb(mp(2, 0));
                }
                else {
                    // +2 di kanan gbs hapus
                    if(st.size() && st.back().se == 1)
                        st.back().fi += 2;
                    else
                        st.pb(mp(2, 1));
                }
            }
            else if(a[j] == 'L') {
                // +2 di kanan bs hapus atau +2 di kiri gbs hapus
                if(opt[j]) {
                    if(st.size() && st.back().se == 1)
                        st.back().fi += 2;
                    else if(st.size() && st.back().se == 0) {
                        if(st.back().fi > 2)
                            st.back().fi -= 2;
                        else if(st.back().fi == 2)
                            st.pop_back();
                        else {
                            st.pop_back();
                            if(st.size() && st.back().se == 1)
                                ++st.back().fi;
                            else
                                st.pb(mp(1, 1));
                        }
                    }
                    else
                        st.pb(mp(2, 1));
                }
                else {
                    if(st.size() && st.back().se == 0)
                        st.back().fi += 2;
                    else
                        st.pb(mp(2, 0));
                }
            }
            else if(a[j] == 'S') {
                x = 1;
                // try check S functionality
                // + 1 di kanan (bs hapus) 
                // + 1 di kiri (gbs hapus)
                if(st.size() && st.back().se == 0) {
                    if(st.back().fi == 1)
                        st.pop_back();
                    else
                        --st.back().fi;
                }
                else {
                    if(st.size() && st.back().se == 1)
                        ++st.back().fi;
                    else
                        st.pb(mp(1, 1));
                }
                if(st.size() && st.back().se == 0)
                    ++st.back().fi;
                else
                    st.pb(mp(1, 0));
            }
            else if(a[j] == 'Z') {
                x = 1;
                // + 1 di kiri (bs hapus)
                // + 1 di kanan (gbs hapus)
                if(st.size() && st.back().se == 1) {
                    if(st.back().fi == 1)
                        st.pop_back();
                    else
                        --st.back().fi;
                }
                else {
                    if(st.size() && st.back().se == 0)
                        ++st.back().fi;
                    else
                        st.pb(mp(1, 0));
                }
                if(st.size() && st.back().se == 1)
                    ++st.back().fi;
                else
                    st.pb(mp(1, 1));
            }
            else {
                x = 1;
                // kasus T
                // +2 di satu sisi, satunya bs hapus, satunya gabisa
                if(opt[j]) {
                    // di kiri aja
                    if(st.size() && st.back().se == 1) {
                        if(st.back().fi == 1)
                            st.pop_back();
                        else
                            --st.back().fi;
                        if(st.size() && st.back().se == 0)
                            ++st.back().fi;
                        else
                            st.pb(mp(1, 0));
                    }
                    else if(st.size() && st.back().se == 0) {
                        st.back().fi += 2;
                    }
                    else {
                        st.pb(mp(2, 0));
                    }
                }
                else {
                    // di kanan aja
                    if(st.size() && st.back().se == 0) {
                        if(st.back().fi == 1)
                            st.pop_back();
                        else
                            --st.back().fi;
                        if(st.size() && st.back().se == 1)
                            ++st.back().fi;
                        else
                            st.pb(mp(1, 1));
                    }
                    else if(st.size() && st.back().se == 1) {
                        st.back().fi += 2;
                    }
                    else {
                        st.pb(mp(2, 1));
                    }
                }
            }
        }
        if(st.empty()) {
            // berarti bitmask ini answer
            int ans[n + 1];
            for(int j = 1; j <= n; ++j) {
                if(a[j] == 'O')
                    ans[j] = 0;
                else if(a[j] == 'S' || a[j] == 'Z')
                    ans[j] = 1;
                else if(a[j] == 'T') {
                    if(opt[j])
                        ans[j] = 1;
                    else
                        ans[j] = 3;
                }
                else if(a[j] == 'J') {
                    if(opt[j])
                        ans[j] = 1;
                    else
                        ans[j] = 3;
                }
                else {
                    if(opt[j])
                        ans[j] = 3;
                    else
                        ans[j] = 1;
                }
            }
            cout << "YES" << endl;
            for(int i = 1; i <= n; ++i)
                cout << ans[i] << " ";
            cout << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    // AC sol???
    return 0;
}